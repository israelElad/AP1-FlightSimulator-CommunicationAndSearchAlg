#include "FileCacheManager.h"

FileCacheManager::FileCacheManager() {
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
bool FileCacheManager::isSaved(string problem) {
    return this->problemToSolution.count(problem) >= 1;
}

// get the solution. The user have to check if the solution isSaved cameFrom get it.
string FileCacheManager::getSolution(string problem) {
    string solution;
    if (this->problemToSolution.count(problem) < 1) {
        throw "There is no solution to this problem!";
    }
    return this->problemToSolution.at(problem);
}

// save the solution to the problem
void FileCacheManager::saveSolution(string problem, string solution) {
    this->problemToSolution.insert(pair<string, string>(problem, solution));
}

// load all the problems with their solution to the problemToSolution map
void FileCacheManager::loadToMap() {
    fstream file;
    string buffer;
    file.open("problemWithSolutionFile", ios_base::out | ios_base::in);
    getline(file, buffer);
    while (!file.eof()) {
        string problem = buffer;
        getline(file, buffer);
        string solution = buffer;
        this->problemToSolution.insert(pair<string, string>(problem, solution));
        getline(file, buffer);
    }
    file.close();
}

// save all the problems with their solution in the map
void FileCacheManager::saveInFile() {
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



