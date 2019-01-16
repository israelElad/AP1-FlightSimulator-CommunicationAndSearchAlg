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
private:
    Solver<ISearchable<Cell, double> *, vector<State<Cell, double> *>> *solver;
    CacheManager<string, string> *cacheManager;

    string pathVecToStrDirections(vector<State<Cell, double> *> &solutionVector);

    vector<State<Cell, double> *> deathVector1;
    vector<ISearchable<Cell, double> *> deathVector2;
public:
    MyClientHandler(Solver<ISearchable<Cell, double> *, vector<State<Cell, double> *>> *solver,
                    CacheManager<string, string> *cacheManager);

    virtual void handleClient(int newSocketFd);

    string readLineFromSocket(int newSocketFd);

    vector<double> separateDoublesByComma(string &row);

    string eraseSpaces(string str);

    virtual ~MyClientHandler() {
        for (State<Cell, double> *state:this->deathVector1) {
            delete (state);
        }
        for (ISearchable<Cell, double> *iSearchable:this->deathVector2) {
            delete (iSearchable);
        }
    }
};


#endif //PROJECT2_MYCLIENTHANDLER_H
