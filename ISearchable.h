#ifndef PROJECT2_ISEARCHABLE_H
#define PROJECT2_ISEARCHABLE_H

#include <vector>
#include "State.h"

using namespace std;

template<typename T, typename C>

class ISearchable {
public:
    virtual State<T, C> getInitialState() = 0;

    virtual bool getIGoallState() = 0;

    virtual vector<State<T, C>> getAllPossibleStates(State<T, C> state) = 0;
};


#endif //PROJECT2_ISEARCHABLE_H
