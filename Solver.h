#ifndef PROJECT2_SOLVER_H
#define PROJECT2_SOLVER_H

using namespace std;

template<typename P, typename S>

class Solver {
public:
    // Solve a problem
    virtual S solve(P problem) = 0;
};

#endif //PROJECT2_SOLVER_H
