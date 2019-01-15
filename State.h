#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

#include <string>
#include <limits>
#include "State.h"
#include "Cell.h"

using namespace std;

template<typename T, typename C>

class State {
    T state;
    C cost;
    State<T, C> *cameFrom;
    C firstCost;

public:
    explicit State(T state) : state(state) {
        this->state = state;
        this->cameFrom = nullptr;
        this->cost = numeric_limits<C>::infinity();
        this->firstCost = numeric_limits<C>::infinity();
    }

    // check if stateA equal to stateB
    bool operator==(State<T, C> otherState) {
        return (this->state == otherState.getState());
    }

    // check if stateA < stateB
    bool operator<(const State<T, C> *other) const {
        return this->cost < other->getCost();
    }

    // get state
    T getState() {
        return state;
    }

    // get cost
    C getCost() {
        return cost;
    }

    // get the state we came from
    State<T, C> *getCameFrom() {
        return cameFrom;
    }

    // set the state we came from
    void setCameFrom(State<T, C> *newCameFrom) {
        this->cameFrom = newCameFrom;
    }

    // set cost
    void setCost(C cost) {
        this->cost = cost;
    }

    void setFirstCost(C firstCost) {
        State::firstCost = firstCost;
    }

    C getFirstCost() {
        return firstCost;
    }
};


#endif //PROJECT2_STATE_H
