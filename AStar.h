//#ifndef PROJECT2_ASTAR_H
//#define PROJECT2_ASTAR_H
//
//#include <unordered_set>
//#include "ISearcher.h"
//
//using namespace std;
//
//template<typename T, typename C>
//
//class AStar : public ISearcher<vector<State<T, C> *>, T, C> {
//    int numberOfNodesEvaluated = 0;
//    unordered_set<State<T, C> *> closedSet; // a set of states already evaluated
//    unordered_set<State<T, C> *> openSet; // The set of tentative states to be evaluated
//public:
//    // get numberOfNodesEvaluated
//    virtual int getNumberOfNodesEvaluated() {
//        return this->numberOfNodesEvaluated;
//    }
//
//    virtual vector<State<T, C> *> search(ISearchable<T, C> *searchable) {
//        this->openSet.insert(searchable->getInitialState());
//
//        /* g_score[start] := 0 // Cost from start along best known path.
//        // Estimated total cost from start to goal through y.
//        f_score[start] := g_score[start] + heuristic_cost_estimate(start, goal)*/
//
//        while (!this->openSet.empty()) {
//            /* remove the node in openset having the lowest f_score[] value */
//            State<T, C> *n;
//            this->openSet.remove(); //todo:remove
//            this->numberOfNodesEvaluated++;
//            this->closedSet.insert(n);
//            if (*n == *searchable->getIGoallState()) {
//                return this->backTrace(n, searchable);
//            }
//        }
//
//        /*
//        for each neighbor in neighbor_nodes(current)
//        tentative_g_score := g_score[current] + dist_between(current,neighbor)
//        if neighbor in closedset or tentative_g_score >= g_score[neighbor]
//            continue
//        if neighbor not in openset or tentative_g_score < g_score[neighbor]
//            came_from[neighbor] := current
//        g_score[neighbor] := tentative_g_score
//        f_score[neighbor] := g_score[neighbor] + heuristic_cost_estimate(neighbor, goal)
//        if neighbor not in openset
//            add neighbor to openset
//        * */
//    }
//};
//
//
//#endif //PROJECT2_ASTAR_H
