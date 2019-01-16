#include <vector>
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"
#include "MyParallelServer.h"
#include "Cell.h"
#include "Matrix.h"
#include "ISearcher.h"
#include "BestFirstSearch.h"
#include "SolverSearcherAdapter.h"
#include "BreadthFirstSearch.h"
#include "CacheManager.h"
#include "MyClientHandler.h"
#include "DepthFirstSearch.h"
#include "AStar.h"

using namespace std;

int main(int argc, char *argv[]) {

    /* P = ISearchable<Cell, double>*
     * S = vector<State<Cell, double> *>
     * T = Cell
     * C = double
     * */
    if (argc <= 1) {
        cout << "no arguments received!";
        return -1;
    }
    int port = stoi(argv[1]);
    ISearcher<vector<State<Cell, double> *>, Cell, double> *iSearcher = new BestFirstSearch<Cell, double>();
    Solver<ISearchable<Cell, double> *, vector<State<Cell, double> *>> *solver = new SolverSearcherAdapter<vector<State<Cell, double> *>, Cell, double>(
            iSearcher);
    CacheManager<string, string> *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MyClientHandler(solver, cacheManager);
    Server *serial = new MyParallelServer();
    serial->open(port, clientHandler);

    delete (cacheManager);
    delete (iSearcher);
    delete (solver);
    delete (clientHandler);
    delete (serial);

    cout << "hi" << endl;

    return 0;
}