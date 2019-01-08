#ifndef PROJECT2_STRINGREVERSER_H
#define PROJECT2_STRINGREVERSER_H


#include "Solver.h"
#include <string>

template<typename P, typename S>
class StringReverser : public Solver<P, S> {
public:
    // Solve a problem
    virtual string solve(string problem){
        problem.reserve();
        return problem;
    }
};


#endif //PROJECT2_STRINGREVERSER_H
