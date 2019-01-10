#ifndef PROJECT2_MATRIX_H
#define PROJECT2_MATRIX_H

#include "ISearchable.h"
#include "State.h"
#include "Cell.h"

using namespace std;

class Matrix : public ISearchable<Cell, double> {
    int n;
    vector<vector<double>> values;
    State<Cell, double> initialState;
    State<Cell, double> goalState;

public:
    Matrix(int n, vector<vector<double>> &values, State<Cell, double> initialState, State<Cell, double> goalState);

    virtual State<Cell, double> getInitialState();

    virtual State<Cell, double> getIGoallState();

    virtual vector<State<Cell, double>> getAllPossibleStates(State<Cell, double> state);

    double getValue(Cell cell);
};


#endif //PROJECT2_MATRIX_H
