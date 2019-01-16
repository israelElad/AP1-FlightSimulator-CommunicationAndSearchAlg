// Manges the cache

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

#include <string>

using namespace std;

template<typename P, typename S>

class CacheManager {
public:

    // check if the solution to the problem is already saved
    virtual bool isSaved(P problem) = 0;

    // get the solution. The user have to check if the solution isSaved cameFrom get it.
    virtual S getSolution(P problem) = 0;

    // save the solution to the problem
    virtual void saveSolution(P problem, S solution) = 0;

    virtual ~CacheManager() {

    }
};


#endif //PROJECT2_CACHEMANAGER_H
