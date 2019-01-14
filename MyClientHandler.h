#ifndef PROJECT2_MYCLIENTHANDLER_H
#define PROJECT2_MYCLIENTHANDLER_H

#include <string>
#include <vector>
#include "CacheManager.h"
#include "Solver.h"
#include "ClientHandler.h"
#include "Cell.h"
#include "ISearchable.h"

using namespace std;

class MyClientHandler : public ClientHandler {
    Solver<ISearchable<Cell, double>*, vector<State<Cell, double> *>> *solver;
    CacheManager<string, string> *cacheManager;
public:
    MyClientHandler(Solver<ISearchable<Cell, double>*, vector<State<Cell, double> *>> *solver, CacheManager<string, string> *cacheManager);

    virtual void handleClient(int newSocketFd);

    string readLineFromSocket(int newSocketFd);

    vector<double> separateDoublesByComma(string &row);
};


#endif //PROJECT2_MYCLIENTHANDLER_H
