#ifndef PROJECT2_MYPRIORITYQUEUE_H
#define PROJECT2_MYPRIORITYQUEUE_H

#include <queue>
#include <algorithm>
#include "State.h"

using namespace std;

template<typename T>

class MyPriorityQueue : public std::priority_queue<T, std::vector<T>> {
public:
    bool remove(const T &value) {
        auto it = std::find(this->c.begin(), this->c.end(), value);
        if (it != this->c.end()) {
            this->c.erase(it);
            // todo: check if necessary
            std::make_heap(this->c.begin(), this->c.end(), this->comp);
            return true;
        } else {
            return false;
        }
    }
};


#endif //PROJECT2_MYPRIORITYQUEUE_H
