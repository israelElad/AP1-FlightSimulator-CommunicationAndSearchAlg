// save solutions in files on the disk

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>

using namespace std;

template<typename P, typename S>
class FileCacheManager : public CacheManager<P, S> {
    unordered_map<P, S> problemToSolution;
public:
    FileCacheManager();

    // check if the solution to the problem is already saved
    virtual bool isSaved(P problem);

    // get the solution. The user have to check if the solution isSaved before get it.
    virtual S getSolution(P problem);

    // save the solution to the problem
    virtual void saveSolution(P problem, S solution);

    // load all the problems with their solution to the problemToSolution map
    void loadToMap();

    // save all the problems with their solution in the map
    void saveInFile();

    ~FileCacheManager();
};


#endif //PROJECT2_FILECACHEMANAGER_H
