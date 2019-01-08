#ifndef PROJECT2_STRINGREVERSER_H
#define PROJECT2_STRINGREVERSER_H


#include "Solver.h"
#include <string>

template<typename P, typename S>

class StringReverser : public Solver<P, S> {
public:
    // Solve a problem
    virtual S solve(P problem){
        string problemStr = to_string(problem);
        return problemStr.reserve();
    }
};


#endif //PROJECT2_STRINGREVERSER_H
