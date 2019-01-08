#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H


#include <unordered_set>
#include "Searcher.h"

template<typename T, typename C>

class BestFirstSearch : public Searcher<T, C> {
    virtual vector<State<T,C>> search(ISearchable<T, C> &searchable) {
        this->addToOpenList(searchable.getInitialState());
        unordered_set<State<T, C>> closedSet; // a set of states already evaluated
        // while openList is not empty
        while (this->openListSize() > 0) {
            // Remove the best node from OPEN
            State<T, C> n = this->popOpenList();
            closedSet.insert(n);
            if (n == searchable.getIGoallState()){

            }
        }

    }
};


#endif //PROJECT2_BESTFIRSTSEARCH_H
