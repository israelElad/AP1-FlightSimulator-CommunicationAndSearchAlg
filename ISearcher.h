#ifndef PROJECT2_ISEARCHER_H
#define PROJECT2_ISEARCHER_H


#include "ISearchable.h"

template<typename T, typename C>

class ISearcher {
public:
    // the search method
    virtual vector<State<T, C>*> search(ISearchable<T, C>* searchable) = 0;
    // get how many nodes were evaluated by the algorithm
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //PROJECT2_ISEARCHER_H
