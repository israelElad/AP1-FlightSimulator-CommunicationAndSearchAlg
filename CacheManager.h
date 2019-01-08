// Manges the cache

#ifndef PROJECT2_CACHEMANAGER_H
#define PROJECT2_CACHEMANAGER_H

#include <string>

using namespace std;

class CacheManager {
public:
    virtual bool isSaved(const string &problem) = 0;

    virtual string getSolution(const string &problem) = 0;

    virtual void saveSolution(const string &problem, const string &solution) = 0;
};

#endif //PROJECT2_CACHEMANAGER_H
