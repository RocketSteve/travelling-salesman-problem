#include "WebsocketServer.h"
#include "../InstanceFileReader/InstanceFileReader.h"
#include "../SimulatedAnnealingSolver/SimulatedAnnealingSolver.h"
#include <fstream>
#include <string>

WebsocketServer::WebsocketServer(int port) {
    this->port = port;
    endpoint.init_asio();
    endpoint.set_open_handler([this](auto &&PH1) { onOpen(std::forward<decltype(PH1)>(PH1)); });
    endpoint.set_close_handler([this](auto &&PH1) { onClose(std::forward<decltype(PH1)>(PH1)); });
    endpoint.set_message_handler([this](auto &&PH1, auto &&PH2) {
        onMessage(std::forward<decltype(PH1)>(PH1), std::forward<decltype(PH2)>(PH2));
    });
}
void WebsocketServer::run() {
    endpoint.listen(port);
    endpoint.start_accept();
    try {
        endpoint.run();
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
        this->stop();
    }
}
void WebsocketServer::onOpen(const connection_hdl &hdl) {
    cout << "New client connected " << endl;
    {
        lock_guard<mutex> guard(this->connectionListMutex);
        this->openConnections.push_back(hdl);
    }
}

void WebsocketServer::onClose(const connection_hdl &hdl) {
    cout << "Client disconnected" << endl;
    {
        std::lock_guard<std::mutex> lock(this->connectionListMutex);
        auto connVal = hdl.lock();
        auto newEnd = std::remove_if(this->openConnections.begin(), this->openConnections.end(),
                                     [&connVal](const connection_hdl &elem) {
                                         if (elem.expired()) { return true; }
                                         auto elemVal = elem.lock();
                                         if (elemVal.get() == connVal.get()) { return true; }
                                         return false;
                                     });
        this->openConnections.resize(std::distance(openConnections.begin(), newEnd));
    }
}

void WebsocketServer::onMessage(const connection_hdl &hdl, const server::message_ptr &msg) {
    std::string filename;
    {
        std::lock_guard<std::mutex> lock(this->connectionListMutex);
        filename = std::to_string(this->fileNumber) + ".txt";
        std::ofstream temp_file(filename.c_str());
        temp_file << msg->get_payload();
        temp_file.close();
        this->fileNumber++;
    }
    InstanceFileReader instance(filename);
    SimulatedAnnealingSolver solver(&instance);
    solver.greedySolve();
    std::string path = "Greedy:";
    for (AdjacencyList<CoordinateWithVisitedState> *i: solver.answer) { path += " " + std::to_string(i->getId()); }
    websocketpp::lib::error_code ec;
    std::cout << "Greedy path for client send " << path << std::endl;
    this->endpoint.send(hdl, path, websocketpp::frame::opcode::text, ec);
    if (ec) { std::cout << "Send failed: " << ec.message() << std::endl; }
    solver.solve();
    path = "SimulatedAnnealing:";
    for (AdjacencyList<CoordinateWithVisitedState> *i: solver.answer) { path += " " + std::to_string(i->getId()); }
    std::cout << "Simulated Annealing path for client send " << path << std::endl;
    this->endpoint.send(hdl, path, websocketpp::frame::opcode::text);
}

void WebsocketServer::stop() {
    unique_lock<mutex> con_lock(this->connectionListMutex);
    this->endpoint.stop_listening();
    this->endpoint.stop();
}

WebsocketServer::~WebsocketServer() { this->stop(); }
