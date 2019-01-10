#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H


#include <unordered_set>
#include "Searcher.h"

template<typename T, typename C>

class BestFirstSearch : public Searcher<T, C> {
    virtual vector<State<T, C>> search(ISearchable<T, C> &searchable) { //todo:solution ?
        this->addToOpenPriorityQueue(searchable.getInitialState());
        unordered_set<State<T, C>> closedSet; // a set of states already evaluated
        // while openPriorityQueue is not empty
        while (this->openPriorityQueueSize() > 0) {
            // Remove the best node from OPEN
            State<T, C> n = this->popOpenPriorityQueue();
            closedSet.insert(n);
            if (n == searchable.getIGoallState()) {
                return backTrace(n, searchable);
            }
            // calling the delegated method, returns a vector of states with n as a parent
            vector<State<T, C>> succerssors = searchable.getAllPossibleStates(n); //todo:set ?
            for (State<T, C> s : succerssors) {
                //  If s is not in CLOSED and s is not in OPEN
                if ((!closedSet.count(s)) && (!this->openPriorityQueueContaines(s))) {
                    s.setCameFrom(n);
                    s.setCost(s.getCost() + s.getCameFrom().getCost());
                    this->addToOpenPriorityQueue(s);
                } else {
                    if (!closedSet.count(s)) {
                        if ((s.getCost() < this->getStateFromOpenPriorityQueue(s).getCost()) {
                            this->openPriorityQueue.remove(s); // we remove n with bigger cost
                            this->addToOpenPriorityQueue(s); // we add n with chipper cost
                        }
                    }
                }
            }
        }
        return nullptr;
    }
};


#endif //PROJECT2_BESTFIRSTSEARCH_H
