#ifndef PROJECT2_MYPRIORITYQUEUE_H
#define PROJECT2_MYPRIORITYQUEUE_H

#include <queue>
#include <algorithm>
#include "State.h"

using namespace std;

template<typename T, typename C>

struct CompareCost : public std::binary_function<State<T,C>*, State<T,C>*, bool>
{
    bool operator()(State<T,C>* lhs, State<T,C>* rhs) const
    {
        return lhs->getCost() > rhs->getCost();
    }
};

template<typename T, typename C>

class MyPriorityQueue : public std::priority_queue<State<T, C>*, vector<State<T, C>*>, CompareCost<T, C>> {

public:

    bool remove(State<T, C>* &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        } else {
            return false;
        }
    }
};


#endif //PROJECT2_MYPRIORITYQUEUE_H
