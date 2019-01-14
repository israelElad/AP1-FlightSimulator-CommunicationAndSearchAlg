#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H


#include <unordered_set>
#include <set>
#include "Searcher.h"

template<typename T, typename C>

class BestFirstSearch : public Searcher<vector<State<T, C> *>,T, C> {
    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) {
        this->addToOpenPriorityQueue(searchable->getInitialState());
        unordered_set<State<T, C>*> closedSet; // a set of states already evaluated
        // while openPriorityQueue is not empty
        while (!this->openPriorityQueue.empty()) {
            // Remove the best node from OPEN
            State<T, C> *n = this->openPriorityQueue.top();
            this->openPriorityQueue.pop();
            closedSet.insert(n);
            if (*n == *searchable->getIGoallState()) {
                return this->backTrace(n, searchable);
            }
            // calling the delegated method, returns a vector of states with n as a parent
            vector<State<T, C> *> successors = searchable->getAllPossibleStates(n);
            for (State<T, C> *s : successors) {
                if (s->getCost() == -1){
                    s->setCost(numeric_limits<C>::infinity());
                }
                //  If s is not in CLOSED and s is not in OPEN
                if ((!setContains(closedSet, s)) && (!this->openPriorityQueueContains(s))) {
                    s->setCameFrom(n);
                    s->setCost(s->getCost() + s->getCameFrom()->getCost());
                    this->addToOpenPriorityQueue(s);
                } else {
                    if (!setContains(closedSet, s)) {
                        s->setCameFrom(n);
                        s->setCost(s->getCost() + s->getCameFrom()->getCost());
                        double sOCost = this->getStateFromOpenPriorityQueue(s)->getCost();
                        double sCost = s->getCost();
                        if (s->getCost() < this->getStateFromOpenPriorityQueue(s)->getCost()) {
                            this->openPriorityQueue.remove(s); // we remove n with bigger cost
                            this->addToOpenPriorityQueue(s); // we add n with chipper cost
                        }
                    }
                }
            }
        }
    }

    bool setContains(unordered_set<State<T, C> *> set1, State<T, C> *s) {
        for (State<T, C> *s1 : set1) {
            if (*s == *s1) {
                return true;
            }
        }
        return false;
    }
};


#endif //PROJECT2_BESTFIRSTSEARCH_H
