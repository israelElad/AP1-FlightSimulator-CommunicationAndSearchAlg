#ifndef PROJECT2_DEPTHFIRSTSEARCH_H
#define PROJECT2_DEPTHFIRSTSEARCH_H

#include "ISearcher.h"
#include <stack>
#include <unordered_set>
#include <iostream>

using namespace std;

template<typename T, typename C>

class DepthFirstSearch : public ISearcher<vector<State<T, C> *>, T, C> {
    int numberOfNodesEvaluated = 0;
    stack<State<T, C> *> stackStates;
    unordered_set<State<T, C> *> visited;
public:
    // get numberOfNodesEvaluated
    virtual int getNumberOfNodesEvaluated() {
        return this->numberOfNodesEvaluated;
    }

    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) {
        this->stackStates.push(searchable->getInitialState());
        this->visited.insert(searchable->getInitialState());
        // while stackStates is not empty
        while (!this->stackStates.empty()) {
            // Remove the first state from stackStates
            State<T, C> *n = this->stackStates.top();
            this->stackStates.pop();
            this->numberOfNodesEvaluated++;
            if (*n == *searchable->getIGoallState()) {
                vector<State<Cell, double>*> backTraceV = this->backTrace(n, searchable);

                cout<<this->numberOfNodesEvaluated<<endl;
                double c = 0;
                for (State<Cell, double> *state: backTraceV) {
                    c += state->getFirstCost();
                }
                cout << c << endl;

                this->resetAllFields();
                return backTraceV;
            }
            // calling the delegated method, returns a vector of states with n as a parent
            vector<State<T, C> *> successors = searchable->getAllPossibleStates(n);
            for (State<T, C> *s : successors) {
                if (!visitedContains(s) && (s->getCost() != -1)) {
                    s->setCameFrom(n);
                    this->stackStates.push(s);
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

    // go over visited
    bool visitedContains(State<T, C> *s) {
        for (State<T, C> *s1 : this->visited) {
            if (*s == *s1) {
                return true;
            }
        }
        return false;
    }

    void resetAllFields() {
        this->numberOfNodesEvaluated = 0;
        this->stackStates = stack<State<T, C> *>();
        this->visited.clear();
    }
};


#endif //PROJECT2_DEPTHFIRSTSEARCH_H
