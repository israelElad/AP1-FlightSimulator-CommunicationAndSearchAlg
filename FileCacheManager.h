// save solutions in files on the disk

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>
#include <fstream>

using namespace std;

class FileCacheManager : public CacheManager<string, string> {
    unordered_map<string, string> problemToSolution;
public:
    FileCacheManager();

    // check if the solution to the problem is already saved
    virtual bool isSaved(const string &problem);

    // get the solution. The user have to check if the solution isSaved cameFrom get it.
    virtual string getSolution(const string &problem);

    // save the solution to the problem
    virtual void saveSolution(const string &problem, const string &solution);

    // load all the problems with their solution to the problemToSolution map
    void loadToMap();

    // save all the problems with their solution in the map
    void saveInFile();

    ~FileCacheManager();
};


#endif //PROJECT2_FILECACHEMANAGER_H
