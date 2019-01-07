// save solutions in files on the disk

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H


#include "CacheManager.h"

template<typename P, typename S>
class FileCacheManager : public CacheManager<P, S> {

    // check if the solution to the problem is already saved
    virtual void isSaved(P problem);

    // get the solution
    virtual S getSolution(P problem);

    // save the solution to the problem
    virtual void saveSolution(P problem, S solution);
};


#endif //PROJECT2_FILECACHEMANAGER_H
