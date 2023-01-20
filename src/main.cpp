#include "classes/WebsocketServer/WebsocketServer.h"

int main(int argc, char *argv[]) {
    int port = 1025;
    if (argc >= 1) { port = std::stoi(argv[1]); };
    WebsocketServer websocketServer(port);
    std::cout << "Server start listening" << std::endl;
    websocketServer.run();
    return 0;
}
