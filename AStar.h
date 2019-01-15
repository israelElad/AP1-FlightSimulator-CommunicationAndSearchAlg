#ifndef PROJECT2_ASTAR_H
#define PROJECT2_ASTAR_H

#include <unordered_set>
#include <cmath>
#include "MyPriorityQueue.h"
#include "AbstractSearch.h"

using namespace std;

template<typename T, typename C>

class AStar : public AbstractSearch<T, C> {
public:
    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) {
        State<Cell, double> *start = searchable->getInitialState();
        // Estimated total cost from start to goal through y.
        start->setCost(start->getCost() + this->heuristicFunc(start, searchable));
        this->openPriorityQueue.push(searchable->getInitialState());
        // while openPriorityQueue is not empty
        while (!this->openPriorityQueue.empty()) {
            // remove the node in openPriorityQueue having the lowest cost
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
                if ((!setContains(s)) && (!this->openPriorityQueueContains(s))) {
                    s->setCameFrom(n);
                    s->setCost(s->getCost() + s->getCameFrom()->getCost() + heuristicFunc(s));
                    this->openPriorityQueue.push(s);
                } else {
                    if (!setContains(s)) {
                        s->setCameFrom(n);
                        s->setCost(s->getCost() + s->getCameFrom()->getCost() + heuristicFunc(s));
                        if (s->getCost() < this->getStateFromOpenPriorityQueue(s)->getCost()) {
                            this->openPriorityQueue.remove(s); // we remove n with bigger cost
                            this->openPriorityQueue.push(s); // we add n with chipper cost
                        }
                    }
                }
            }
        }
    }

    double heuristicFunc(State<Cell, double> *state, ISearchable<T, C> *searchable) {
        State<Cell, double> *exit = searchable->getIGoallState();
        int i1 = state->getState().getI();
        int j1 = state->getState().getJ();
        int i2 = exit->getState().getI();
        int j2 = exit->getState().getJ();
        double distance = sqrt(pow(j2 - j1, 2) + pow(i2 - i1, 2));
        return distance;
    }
};


#endif //PROJECT2_ASTAR_H
