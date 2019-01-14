#ifndef PROJECT2_BREADTHFIRSTSEARCH_H
#define PROJECT2_BREADTHFIRSTSEARCH_H

#include "Searcher.h"

template<typename T, typename C>

class BreadthFirstSearch : public Searcher<vector<State<T, C> *>, T, C> {
    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) {

    }
};


#endif //PROJECT2_BREADTHFIRSTSEARCH_H
