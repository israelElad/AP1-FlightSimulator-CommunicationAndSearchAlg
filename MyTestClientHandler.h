//Client handler(will read client messages and handle them) for testing infrastructure.

#ifndef PROJECT2_MYTESTCLIENTHANDLER_H
#define PROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"

template<typename P, typename S>
class MyTestClientHandler :public ClientHandler{

private:
    Solver<P,S> solver;
    CacheManager<P,S> cacheManager;
public:
    MyTestClientHandler(const Solver<P, S> &solver, const CacheManager<P, S> &cacheManager);
    virtual void handleClient(istream istream1, ostream ostream1);
};


#endif //PROJECT2_MYTESTCLIENTHANDLER_H
