#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H


#include <unordered_set>
#include <set>
#include "MyPriorityQueue.h"
#include "AbstractSearch.h"

template<typename T, typename C>

class BestFirstSearch : public AbstractSearch<T, C> {
public:
    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) {
        this->openPriorityQueue.push(searchable->getInitialState());
        // while openPriorityQueue is not empty
        while (!this->openPriorityQueue.empty()) {
            // Remove the best state from OPEN
            State<T, C> *n = this->openPriorityQueue.top();
            this->openPriorityQueue.pop();
            this->numberOfNodesEvaluated++;
            this->closedSet.insert(n);
            if (*n == *searchable->getIGoallState()) {
                vector<State<Cell, double>*> backTraceV = this->backTrace(n, searchable);;
                this->resetAllFields();
                return backTraceV;
            }
            // calling the delegated method, returns a vector of states with n as a parent
            vector<State<T, C> *> successors = searchable->getAllPossibleStates(n);
            for (State<T, C> *s : successors) {
                if (s->getCost() == -1) {
                    s->setCost(numeric_limits<C>::infinity());
                }
                //  If s is not in CLOSED and s is not in OPEN
                if ((!this->setContains(s)) && (!this->openPriorityQueueContains(s))) {
                    s->setCameFrom(n);
                    s->setCost(s->getCost() + s->getCameFrom()->getCost());
                    this->openPriorityQueue.push(s);
                } else {
                    if (!this->setContains(s)) {
                        s->setCameFrom(n);
                        s->setCost(s->getCost() + s->getCameFrom()->getCost());
                        if (s->getCost() < this->getStateFromOpenPriorityQueue(s)->getCost()) {
                            this->openPriorityQueue.remove(s); // we remove n with bigger cost
                            this->openPriorityQueue.push(s); // we add n with chipper cost
                        }
                    }
                }
            }
        }
    }
};


#endif //PROJECT2_BESTFIRSTSEARCH_H
