#ifndef PROJECT2_SEARCHER_H
#define PROJECT2_SEARCHER_H

#include <queue>
#include "ISearcher.h"
#include "State.h"

using namespace std;

template<typename T, typename C>

class Searcher : public ISearcher<T, C> {
// members
private:
    int numberOfNodesEvaluated{};

protected:
    priority_queue<State<T, C>> openList;

// methods
public:
    Searcher() {
        this->numberOfNodesEvaluated = 0;
    }

    // get OpenList size
    int openListSize() {
        return static_cast<int>(this->openList.size());
    }

    // get numberOfNodesEvaluated
    virtual int getNumberOfNodesEvaluated() {
        return numberOfNodesEvaluated;
    }

    // abstract method search
    virtual vector<State<T, C>> search(ISearchable<T, C> &searchable) = 0;

    // add new state to OpenList
    void addToOpenList(State<T, C> newState) {
        this->openList.push(newState);
    }

    vector<State<T, C>> backTrace() {

    }

protected:
    // pop best state from openList
    State<T, C> popOpenList() {
        this->numberOfNodesEvaluated++;
        if (!this->openList.empty()) {
            State<T, C> top = this->openList.top();
            this->openList.pop();
            return top;
        }
        return nullptr;
    }
};

#endif //PROJECT2_SEARCHER_H
