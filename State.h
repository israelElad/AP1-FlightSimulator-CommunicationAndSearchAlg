#ifndef PROJECT2_STATE_H
#define PROJECT2_STATE_H

template<typename T, typename C>

class State {
    T state;
    C cost;
    State<T, C> before;
public:
    State() {
        this->before = nullptr;
    }
    bool operator==(State<T, C> otherState) {
        return ((this->state == otherState.getState()) && (this->cost == otherState.getCost()) &&
                (this->before == otherState.getBefore()));
    }

    T getState() {
        return state;
    }

    C getCost() {
        C State<T, C>::getCost() {
            return cost;
        }
    }

    const State<T, C> &getBefore() {
        return before;
    }
};


#endif //PROJECT2_STATE_H
