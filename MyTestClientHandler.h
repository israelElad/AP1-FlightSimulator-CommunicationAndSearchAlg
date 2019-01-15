// Client handler(will read client messages and handle them) for testing infrastructure.

#ifndef PROJECT2_MYTESTCLIENTHANDLER_H
#define PROJECT2_MYTESTCLIENTHANDLER_H

#include "CacheManager.h"
#include "Solver.h"
#include "ClientHandler.h"

class MyTestClientHandler : public ClientHandler {
    Solver<string, string> *solver;
    CacheManager<string, string> *cacheManager;
public:
    MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cacheManager);

    virtual void handleClient(int newSocketFd);

    string readLineFromSocket(int newSocketFd);
};


#endif //PROJECT2_MYTESTCLIENTHANDLER_H
