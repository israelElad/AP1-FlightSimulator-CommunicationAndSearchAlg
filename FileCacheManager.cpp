#include <fstream>
#include <map>
#include "FileCacheManager.h"

template<typename P, typename S>
FileCacheManager<P, S>::FileCacheManager() {
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

template<typename P, typename S>

bool FileCacheManager<P, S>::isSaved(P problem) {
    return this->problemToSolution.count(problem) >= 1;
}

template<typename P, typename S>

S FileCacheManager<P, S>::getSolution(P problem) {
    S solution;
    if (this->problemToSolution.count(problem) < 1) {
        throw "There is no solution to this problem!";
    }
    return this->problemToSolution.at(problem);
}

template<typename P, typename S>

void FileCacheManager<P, S>::saveSolution(P problem, S solution) {
    this->problemToSolution.insert(pair<P, S>(problem, solution));
}

template<typename P, typename S>
void FileCacheManager<P, S>::loadToMap() {
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

template<typename P, typename S>
void FileCacheManager<P, S>::saveInFile() {
    //open problemWithSolutionFile file
    fstream file;
    string buffer;
    file.open("problemWithSolutionFile", ios_base::out | ios_base::in);
    typename std::map<P, S>::iterator itPTS = this->problemToSolution.begin();
    while (itPTS != this->problemToSolution.end()) {
        file << itPTS->first << endl;
        file << itPTS->second << endl;
        itPTS++;
    }
    file.close();
}

template<typename P, typename S>
FileCacheManager<P, S>::~FileCacheManager() {
    saveInFile();
}

