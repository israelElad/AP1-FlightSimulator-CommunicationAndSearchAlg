#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include "ISearchable.h"
#include "State.h"
#include "Cell.h"

using namespace std;

class Matrix : public ISearchable<Cell, double> {
    int n;
    int m;
    vector<vector<double>> values;
    State<Cell, double> *initialState;
    State<Cell, double> *goalState;
    vector<State<Cell, double> *> deathVector;

public:
    Matrix(int n, int m, vector<vector<double>> &values, State<Cell, double> *initialState,
           State<Cell, double> *goalState);

    //get initial state
    virtual State<Cell, double> *getInitialState();

    //get goal state
    virtual State<Cell, double> *getIGoallState();

    //get all possible next states from current state received
    virtual vector<State<Cell, double> *> getAllPossibleStates(State<Cell, double> *state);

    //get Cell's value
    double getValue(Cell cell);

    virtual ~Matrix() {
        for (State<Cell, double> *state:this->deathVector) {
            delete (state);
        }
    }
};

#endif //PROJECT2_MATRIX_H
