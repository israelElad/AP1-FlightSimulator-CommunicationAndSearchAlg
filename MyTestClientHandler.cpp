#include <iostream>
#include <cstring>
#include "MyTestClientHandler.h"


template<typename P, typename S>
MyTestClientHandler<P, S>::MyTestClientHandler(const Solver<P, S> &solver, const CacheManager<P, S> &cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

template<typename P, typename S>
void MyTestClientHandler<P, S>::handleClient(istream istream1, ostream ostream1) {
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
