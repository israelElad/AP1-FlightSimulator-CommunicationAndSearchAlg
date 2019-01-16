#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

using namespace std;

// Determining the type and handling of the call with the client
class ClientHandler {
public:
    virtual void handleClient(int newSocketFd) = 0;

    virtual ~ClientHandler() {

    }
};


#endif //PROJECT2_CLIENTHANDLER_H
