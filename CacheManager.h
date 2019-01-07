// Manges the cache

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

template<typename P, typename S>

class CacheManager {
public:
    virtual void isSaved(P problem) = 0;

    virtual S getSolution(P problem) = 0;

    virtual void saveSolution(P problem, S solution) = 0;
};

#endif //PROJECT2_CACHEMANAGER_H
