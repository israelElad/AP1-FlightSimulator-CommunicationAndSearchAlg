#ifndef PROJECT2_STRINGREVERSER_H
#define PROJECT2_STRINGREVERSER_H


#include "Solver.h"

template<typename P, typename S>

class StringReverser : public Solver<P, S> {
public:
    // Solve a problem
    virtual S solve(P problem);
};


#endif //PROJECT2_STRINGREVERSER_H
