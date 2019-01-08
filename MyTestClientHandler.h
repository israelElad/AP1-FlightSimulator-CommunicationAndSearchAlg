// Client handler(will read client messages and handle them) for testing infrastructure.

#ifndef PROJECT2_MYTESTCLIENTHANDLER_H
#define PROJECT2_MYTESTCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <iostream>
#include <cstring>

template<typename P, typename S>
class MyTestClientHandler :public ClientHandler{
    Solver<P,S> solver;
    CacheManager<P,S> cacheManager;
public:
    MyTestClientHandler(const Solver<P, S> &solver, const CacheManager<P, S> &cacheManager){
        this->solver = solver;
        this->cacheManager = cacheManager;
    }
    virtual void handleClient(istream istream1, ostream ostream1) {
        char buffer[256];
        istream1.getline(buffer, 256);
        while (strcmp(buffer, "end") != 0) {
            bool checkResult = this->cacheManager.isSaved(buffer);
            if (checkResult) {
                S solution = this->cacheManager.getSolution(buffer);
                ostream1 << solution;
            } else {
                S solution = this->solver.solve(buffer);
                this->cacheManager.saveSolution(buffer, solution);
                ostream1 << solution;
            }
            flush(ostream1);
            istream1.getline(buffer, 256);
        }
    }
};


#endif //PROJECT2_MYTESTCLIENTHANDLER_H
