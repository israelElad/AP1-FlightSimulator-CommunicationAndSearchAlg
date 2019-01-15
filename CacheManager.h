// Manges the cache

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

#include <string>

using namespace std;

template<typename P, typename S>

class CacheManager {
public:
    virtual bool isSaved(P problem) = 0;

    virtual S getSolution(P problem) = 0;

    virtual void saveSolution(P problem, S solution) = 0;

    virtual ~CacheManager(){

    }
};

#endif //PROJECT2_CACHEMANAGER_H
