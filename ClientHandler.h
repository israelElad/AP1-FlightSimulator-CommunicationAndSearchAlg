// Determining the type and handling of the call with the customer

#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

using namespace std;

class ClientHandler {
public:
    // read the client messages and write the answers of the server using socket id
    virtual void handleClient(int socketFd) = 0;
};

#endif //PROJECT2_CLIENTHANDLER_H
