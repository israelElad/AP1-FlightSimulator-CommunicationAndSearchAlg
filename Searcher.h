#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

#include <queue>
#include "ISearcher.h"
#include "State.h"
#include "MyPriorityQueue.h"

using namespace std;

template<typename T, typename C>

class Searcher : public ISearcher<T, C> {
// members
private:
    int numberOfNodesEvaluated{};

protected:
    MyPriorityQueue<T, C> openPriorityQueue;

// methods
public:

    Searcher() {
        this->numberOfNodesEvaluated = 0;
    }

    // get openPriorityQueue size
    int openPriorityQueueSize() {
        return static_cast<int>(this->openPriorityQueue.size());
    }

    // get numberOfNodesEvaluated
    virtual int getNumberOfNodesEvaluated() {
        return numberOfNodesEvaluated;
    }

    // abstract method search
    virtual vector<State<T, C>*> search(ISearchable<T, C> *searchable) = 0;

    // add new state to openPriorityQueue
    void addToOpenPriorityQueue(State<T, C>* newState) {
        this->openPriorityQueue.push(newState);
    }

    // go from the end of the path to the beginning and create a path
    vector<State<T, C>*> backTrace(State<T, C>* goallState, ISearchable<T, C> *searchable) {
        vector<State<T, C>*> path;
        path.push_back(goallState);
        while (!(*goallState == *searchable->getInitialState())) {
            path.push_back(goallState->getCameFrom());
            goallState = goallState->getCameFrom();
        }
        // todo:reverse
        return path;
    }

    // go over openPriorityQueue
    bool openPriorityQueueContains(State<T, C> *state) {

        MyPriorityQueue<T, C> copy = this->openPriorityQueue;
        while (!copy.empty()) {
            State<T, C>* state1 = copy.top();
            copy.pop();
            if (*state == *state1) {
                return true;
            }
        }
        return false;
    }

    // get state from openPriorityQueue
    State<T, C>* getStateFromOpenPriorityQueue(State<T, C>* state) {
        MyPriorityQueue<T, C> copy = this->openPriorityQueue;
        while (!copy.empty()) {
            State<T, C>* state1 = copy.top();
            copy.pop();
            if (*state == *state1) {
                return state1;
            }
        }
    }
};

#endif //PROJECT2_SEARCHER_H
