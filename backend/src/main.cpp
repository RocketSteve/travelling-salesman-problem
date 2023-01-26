#include "classes/WebsocketServer/WebsocketServer.h"
#include <signal.h>

std::function<void(int)> shutdown_handler;
void signal_handler(int signal) { shutdown_handler(signal); }

int main(int argc, char *argv[]) {
    int port = 1025;
    if (argc >= 1) { port = std::stoi(argv[1]); };
    WebsocketServer websocketServer(port);
    std::cout << "Server start listening" << std::endl;
    websocketServer.run();
    shutdown_handler = [&](int signal) { websocketServer.stop(); };
    signal(SIGTERM, signal_handler);
    signal(SIGABRT, signal_handler);
    signal(SIGSEGV, signal_handler);
    return 0;
}
