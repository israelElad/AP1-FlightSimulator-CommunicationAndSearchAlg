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
    MyPriorityQueue<State<T, C>> openPriorityQueue;

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
    virtual vector<State<T, C>> search(ISearchable<T, C> &searchable) = 0;

    // add new state to openPriorityQueue
    void addToOpenPriorityQueue(State<T, C> newState) {
        this->openPriorityQueue.push(newState);
    }

    // go from the end of the path to the beginning and create a path
    vector<State<T, C>> backTrace(State<T, C> goallState, ISearchable<T, C> &searchable) {
        vector<State<T, C>> path;
        path.insert(goallState);
        while (!(goallState == searchable.getInitialState())) {
            path.insert(goallState.getCameFrom());
            goallState = goallState.getCameFrom();
        }
        return path;
    }

    // go over openPriorityQueue
    bool openPriorityQueueContaines(State<T, C> state) {
        for (State<T, C> i : this->openPriorityQueue) {
            if (i == state) {
                return true;
            }
        }
        return false;
    }

    // get state from openPriorityQueue
    State<T, C> getStateFromOpenPriorityQueue(State<T, C> state) {
        for (State<T, C> i : this->openPriorityQueue) {
            if (i == state) {
                return i;
            }
            return nullptr;
        }
    }

protected:
    // pop best state from openPriorityQueue
    State<T, C> popOpenPriorityQueue() {
        this->numberOfNodesEvaluated++;
        if (!this->openPriorityQueue.empty()) {
            State<T, C> top = this->openPriorityQueue.top();
            this->openPriorityQueue.pop();
            return top;
        }
        return nullptr;
    }
};

#endif //PROJECT2_SEARCHER_H
