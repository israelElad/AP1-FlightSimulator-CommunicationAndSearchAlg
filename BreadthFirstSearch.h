#ifndef PROJECT2_BREADTHFIRSTSEARCH_H
#define PROJECT2_BREADTHFIRSTSEARCH_H

#include "ISearcher.h"
#include <queue>
#include <unordered_set>

using namespace std;

template<typename T, typename C>

class BreadthFirstSearch : public ISearcher<vector<State<T, C> *>, T, C> {
    int numberOfNodesEvaluated = 0;
    queue<State<T, C> *> q;
    unordered_set<State<T, C> *> visited;
public:
    // get numberOfNodesEvaluated
    virtual int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }

    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) {
        this->q.push(searchable->getInitialState());
        this->visited.insert(searchable->getInitialState());
        // while q is not empty
        while (!this->q.empty()) {
            // Remove the first state from q
            State<T, C> *n = this->q.front();
            this->q.pop();
            this->numberOfNodesEvaluated++;
            if (*n == *searchable->getIGoallState()) {
                return this->backTrace(n, searchable);
            }
            // calling the delegated method, returns a vector of states with n as a parent
            vector<State<T, C> *> successors = searchable->getAllPossibleStates(n);
            for (State<T, C> *s : successors) {
                if ((this->visited.count(s) == 0) && (s->getCost() != -1)) {
                    s->setCameFrom(n);
                    this->q.push(s);
                    this->visited.insert(s);
                }
            }
        }
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
};


#endif //PROJECT2_BREADTHFIRSTSEARCH_H
