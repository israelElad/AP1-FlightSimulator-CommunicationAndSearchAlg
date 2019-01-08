// save solutions in files on the disk

#ifndef PROJECT2_FILECACHEMANAGER_H
#define PROJECT2_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <unordered_map>
#include <fstream>

using namespace std;

template<typename P, typename S>
class FileCacheManager : public CacheManager<P, S> {
    unordered_map<P, S> problemToSolution;
public:
    FileCacheManager(){
        fstream file;
        // will not create file if does not exist
        file.open("problemWithSolutionFile", ios_base::out | ios_base::in);
        if (!file.is_open()) {
            file.clear();
            // will create file if necessary
            file.open("problemWithSolutionFile", ios_base::out);
        }
        file.close();
        loadToMap();
    }

    // check if the solution to the problem is already saved
    virtual bool isSaved(P problem){
        return this->problemToSolution.count(problem) >= 1;
    }

    // get the solution. The user have to check if the solution isSaved before get it.
    virtual S getSolution(P problem){
        S solution;
        if (this->problemToSolution.count(problem) < 1) {
            throw "There is no solution to this problem!";
        }
        return this->problemToSolution.at(problem);
    }

    // save the solution to the problem
    virtual void saveSolution(P problem, S solution){
        this->problemToSolution.insert(pair<P, S>(problem, solution));
    }

    // load all the problems with their solution to the problemToSolution map
    void loadToMap(){
        fstream file;
        string buffer;
        file.open("problemWithSolutionFile", ios_base::out | ios_base::in);
        getline(file, buffer);
        while (!file.eof()) {
            P problem = buffer;
            getline(file, buffer);
            S solution = buffer;
            this->problemToSolution.insert(pair<P, S>(problem, solution));
            getline(file, buffer);
        }
        file.close();
    }

    // save all the problems with their solution in the map
    void saveInFile(){
        //open problemWithSolutionFile file
        fstream file;
        string buffer;
        file.open("problemWithSolutionFile", ios_base::out | ios_base::in);
        auto itPTS = this->problemToSolution.begin();
        while (itPTS != this->problemToSolution.end()) {
            file << itPTS->first << endl;
            file << itPTS->second << endl;
            itPTS++;
        }
        file.close();
    }

    ~FileCacheManager(){
        saveInFile();
    }
};


#endif //PROJECT2_FILECACHEMANAGER_H
