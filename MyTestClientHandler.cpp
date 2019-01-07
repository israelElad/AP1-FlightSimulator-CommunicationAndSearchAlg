
#include "MyTestClientHandler.h"


template<typename P, typename S>
MyTestClientHandler<P, S>::MyTestClientHandler(const Solver<P, S> &solver, const CacheManager<P, S> &cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

template<typename P, typename S>
void MyTestClientHandler<P, S>::handleClient(istream istream1, ostream ostream1) {

}
