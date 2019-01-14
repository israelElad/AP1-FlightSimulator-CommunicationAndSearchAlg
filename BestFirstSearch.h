#ifndef PROJECT2_BESTFIRSTSEARCH_H
#define PROJECT2_BESTFIRSTSEARCH_H


#include <unordered_set>
#include <set>
#include "ISearcher.h"
#include "MyPriorityQueue.h"

template<typename T, typename C>

class BestFirstSearch : public ISearcher<vector<State<T, C> *>, T, C> {
    int numberOfNodesEvaluated = 0;
    MyPriorityQueue<T, C> openPriorityQueue;
    unordered_set<State<T, C> *> closedSet; // a set of states already evaluated
public:
    // get numberOfNodesEvaluated
    virtual int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }

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
                return this->backTrace(n, searchable);
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
                    s->setCost(s->getCost() + s->getCameFrom()->getCost());
                    this->openPriorityQueue.push(s);
                } else {
                    if (!setContains(s)) {
                        s->setCameFrom(n);
                        s->setCost(s->getCost() + s->getCameFrom()->getCost());
                        double sOCost = this->getStateFromOpenPriorityQueue(s)->getCost();
                        double sCost = s->getCost();
                        if (s->getCost() < this->getStateFromOpenPriorityQueue(s)->getCost()) {
                            this->openPriorityQueue.remove(s); // we remove n with bigger cost
                            this->openPriorityQueue.push(s); // we add n with chipper cost
                        }
                    }
                }
            }
        }
    }

    bool setContains(State<T, C> *s) {
        for (State<T, C> *s1 : this->closedSet) {
            if (*s == *s1) {
                return true;
            }
        }
        return false;
    }

    // go from the end of the path to the beginning and create a path
    vector<State<T, C> *> backTrace(State<T, C> *goallState, ISearchable<T, C> *searchable) {
        vector<State<T, C> *> path;
        path.push_back(goallState);
        while (!(*goallState == *searchable->getInitialState())) {
            path.push_back(goallState->getCameFrom());
            goallState = goallState->getCameFrom();
        }
        reverse(path.begin(), path.end());
        return path;
    }

    // go over openPriorityQueue
    bool openPriorityQueueContains(State<T, C> *state) {
        MyPriorityQueue<T, C> copy = this->openPriorityQueue;
        while (!copy.empty()) {
            State<T, C> *state1 = copy.top();
            copy.pop();
            if (*state == *state1) {
                return true;
            }
        }
        return false;
    }

    // get state from openPriorityQueue
    State<T, C> *getStateFromOpenPriorityQueue(State<T, C> *state) {
        MyPriorityQueue<T, C> copy = this->openPriorityQueue;
        while (!copy.empty()) {
            State<T, C> *state1 = copy.top();
            copy.pop();
            if (*state == *state1) {
                return state1;
            }
        }
    }
};


#endif //PROJECT2_BESTFIRSTSEARCH_H
