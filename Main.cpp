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

using namespace std;

int main(int argc, char *argv[]) {
    vector<vector<double>> values = {{0,  1,  2,  3},
                                     {4,  5,  6,  7},
                                     {8,  9,  10, 11},
                                     {12, 13, 14, 15}};
    Cell c1 = Cell(0, 0);
    auto * s = new State<Cell, double>(c1);
    Cell c2 = Cell(3, 3);
    auto * e = new State<Cell, double>(c2);
    ISearchable<Cell, double>* matrix = new Matrix(4, 4, values, s, e);

    ISearcher<vector<State<Cell, double> *>, Cell, double> *b = new BestFirstSearch<Cell, double>();
    Solver<ISearchable<Cell, double>*, vector<State<Cell, double> *>> *solver = new
            SolverSearcherAdapter<vector<State<Cell, double> *>, Cell, double>(b);

    vector<State<Cell, double> *> v = solver->solve(matrix);
}

//
//    Solver<string, string> *solver = new StringReverser();
//    CacheManager *cacheManager = new FileCacheManager();
//    ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
//    int port = stoi(argv[1]);
//    AbstractServer* abstractServer=new MyParallelServer();
//    Server* serial= abstractServer;

//
//    thread serverThread(&Server::open,serial,port, clientHandler);
//    sleep(30);
//    serial->stop();
//    cout<<"opened"<<endl;
//
//    while(true){
//    }
//    return 0;
//}


//
//namespace boot {
//    class Main {
//    public:
//        template<typename P, typename S>
//        int mainProgram(int argc, char *argv) {
//
//            Solver<P, S> *solver = new StringReverser<P, S>();
//            CacheManager<P, S> *cacheManager = new FileCacheManager<P, S>();
//            ClientHandler *clientHandler = MyTestClientHandler<P, S>(solver, cacheManager);
//            int port = argv[0];
//            Server *server = new MySerialServer();
//            server->open(port, clientHandler);
//
//            return 0;
//        }
//    };
//}
//
//using namespace boot;
//
//int main(int argc, char* argv[]){
//    Main m;
//    return m.mainProgram<string,string>(argc,*argv);
//}
