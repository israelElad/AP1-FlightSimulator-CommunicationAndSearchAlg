#include "Matrix.h"

State<Cell, double>* Matrix::getInitialState() {
    return this->initialState;
}

State<Cell, double>* Matrix::getIGoallState() {
    return this->goalState;
}

vector<State<Cell, double>*> Matrix::getAllPossibleStates(State<Cell, double>* state) {
    vector<State<Cell, double>*> allPossibleStates;
    int i = state->getState().getI();
    int j = state->getState().getJ();
    if (i + 1 < n) {
        State<Cell, double>* s = new State<Cell, double>(Cell(i + 1, j));
        s->setCost(this->getValue(s->getState()));
        allPossibleStates.push_back(s);
    }
    if (j + 1 < n) {
        State<Cell, double>* s = new State<Cell, double>(Cell(i, j + 1));
        s->setCost(this->getValue(s->getState()));
        allPossibleStates.push_back(s);
    }
    if (i - 1 >= 0) {
        State<Cell, double>* s = new State<Cell, double>(Cell(i - 1, j));
        s->setCost(this->getValue(s->getState()));
        allPossibleStates.push_back(s);
    }
    if (j - 1 >= 0) {
        State<Cell, double>* s = new State<Cell, double>(Cell(i, j - 1));
        s->setCost(this->getValue(s->getState()));
        allPossibleStates.push_back(s);
    }
    return allPossibleStates;
}

double Matrix::getValue(Cell cell) {
    return this->values[cell.getI()][cell.getJ()];
}
