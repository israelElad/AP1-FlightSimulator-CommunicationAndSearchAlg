// Determining the type and handling of the call with the customer

#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

using namespace std;

class ClientHandler {
public:
    virtual void handleClient(int newSocketFd) = 0;
};

#endif //PROJECT2_CLIENTHANDLER_H
