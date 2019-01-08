// Client handler(will read client messages and handle them) for testing infrastructure.

#ifndef PROJECT2_MYTESTCLIENTHANDLER_H
#define PROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <string>


template<typename P, typename S>
class MyTestClientHandler :public ClientHandler{

private:
    Solver<P,S> solver;
    CacheManager<P,S> cacheManager;
    std::string readLineFromSocket(int socketFd);
public:
    MyTestClientHandler(const Solver<P, S> &solver, const CacheManager<P, S> &cacheManager);
    virtual void handleClient(int socketFd);
};


#endif //PROJECT2_MYTESTCLIENTHANDLER_H
