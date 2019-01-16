#ifndef PROJECT2_ISEARCHABLE_H
#define PROJECT2_ISEARCHABLE_H

#include <vector>
#include "State.h"

using namespace std;

template<typename T, typename C>

class ISearchable {

public:

    //get initial state
    virtual State<T, C> *getInitialState() = 0;

    //get goal state
    virtual State<T, C> *getIGoallState() = 0;

    //get all possible next states from current state received
    virtual vector<State<T, C> *> getAllPossibleStates(State<T, C> *state) = 0;

    virtual ~ISearchable() {}
};

#endif //PROJECT2_ISEARCHABLE_H
