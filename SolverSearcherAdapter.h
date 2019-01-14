#ifndef PROJECT2_SOLVERSEARCHERADAPTER_H
#define PROJECT2_SOLVERSEARCHERADAPTER_H


#include "Solver.h"
#include "ISearcher.h"

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
