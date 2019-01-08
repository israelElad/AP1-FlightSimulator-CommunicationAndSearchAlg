#ifndef PROJECT2_STRINGREVERSER_H
#define PROJECT2_STRINGREVERSER_H


#include "Solver.h"
#include <string>
#include <algorithm>

class StringReverser : public Solver<string, string> {
public:
    // Solve a problem
    virtual string solve(string problem){
        reverse(problem.begin(), problem.end());
        return problem;
    }
};


#endif //PROJECT2_STRINGREVERSER_H
