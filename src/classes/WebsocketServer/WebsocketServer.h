#ifndef TRAVELLING_SALESMAN_PROBLEM_WEBSOCKETSERVER_H
#define TRAVELLING_SALESMAN_PROBLEM_WEBSOCKETSERVER_H

#include <iostream>
#include <utility>
#include <vector>
#include <websocketpp/config/asio_no_tls.hpp>
#include <websocketpp/server.hpp>

using websocketpp::connection_hdl;
using websocketpp::lib::bind;

using websocketpp::lib::condition_variable;
using websocketpp::lib::lock_guard;
using websocketpp::lib::mutex;
using websocketpp::lib::thread;
using websocketpp::lib::unique_lock;

using std::cout;
using std::endl;
using std::vector;

typedef websocketpp::server<websocketpp::config::asio> server;

class WebsocketServer {
public:
    explicit WebsocketServer(int port = 1025);
    ~WebsocketServer();
    void run();
    void onOpen(const connection_hdl &hdl);
    void onClose(const connection_hdl &hdl);
    void onMessage(const connection_hdl &hdl, const server::message_ptr &msg);
    void stop();

private:
    int fileNumber = 0;
    int port;
    server endpoint;
    vector<connection_hdl> openConnections;
    std::mutex connectionListMutex;
};

#endif//TRAVELLING_SALESMAN_PROBLEM_WEBSOCKETSERVER_H