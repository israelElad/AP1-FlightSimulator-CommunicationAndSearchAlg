#ifndef PROJECT2_SOLVERSEARCHERADAPTER_H
#define PROJECT2_SOLVERSEARCHERADAPTER_H


#include "Solver.h"
#include "ISearcher.h"

/**
 * We want to be able to "solve" a search problem.
 * but searchable need searcher, not solver. and solver solve problem. not searchable.
 * thus, we create an object adapter- the adapter connects between the classes without modifying them.
 * it inherits from Solver and contains searcher, so that when solve is being called, it calls the searcher's search
 * method instead of solve.
 */
template<typename S, typename T, typename C>

class SolverSearcherAdapter : public Solver<ISearchable<T, C> *, S> {
    ISearcher<S, T, C> *searcher;
public:
    explicit SolverSearcherAdapter(ISearcher<S, T, C> *searcher) {
        this->searcher = searcher;
    }

    virtual S solve(ISearchable<T, C> *searchable) {
        return this->searcher->search(searchable);
    }
};

#endif //PROJECT2_SOLVERSEARCHERADAPTER_H
