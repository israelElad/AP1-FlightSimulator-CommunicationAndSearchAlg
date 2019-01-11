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

public:
    explicit State(T state):state(state) {
        this->state = state;
        this->cameFrom = nullptr;
        this->cost =numeric_limits<C>::infinity();
    }

    // check if stateA equal to stateB
    bool operator==(State<T, C> otherState) {
        return (this->state == otherState.getState());
    }

    // check if stateA < stateB
    bool operator<(const State<T, C> &other) {
        return this->cost < other.cost;
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
    State<T, C> getCameFrom() {
        return *cameFrom;
    }

    // set the state we came from
    void setCameFrom(const State<T, C> &newCameFrom) {
        this->cameFrom = cameFrom;
    }

    // set cost
    void setCost(C cost) {
        State::cost = cost;
    }

    // hash func for State
    int operator()(const string &key) const {
        hash<string> string_hash;
        string data = to_string(this->state) + to_string(this->cost); //todo: +camefrom ?
        return string_hash(data);
    }
};


#endif //PROJECT2_STATE_H
