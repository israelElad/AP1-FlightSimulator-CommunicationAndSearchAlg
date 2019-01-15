#ifndef PROJECT2_ABSTRACTSEARCH_H
#define PROJECT2_ABSTRACTSEARCH_H

#include <unordered_set>
#include "ISearcher.h"
#include "MyPriorityQueue.h"

template<typename T, typename C>

class AbstractSearch : public ISearcher<vector<State<T, C> *>, T, C> {
protected:
    int numberOfNodesEvaluated = 0;
    MyPriorityQueue<T, C> openPriorityQueue; // The priorityQueue of tentative states to be evaluated
    unordered_set<State<T, C> *> closedSet; // a set of states already evaluated
public:
    // get numberOfNodesEvaluated
    virtual int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }

    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) = 0;

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

    void resetAllFields() {
        this->numberOfNodesEvaluated = 0;
        this->openPriorityQueue = MyPriorityQueue<T, C>();
        this->closedSet.clear();
    }
};

#endif //PROJECT2_ABSTRACTSEARCH_H