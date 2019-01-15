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

using namespace std;

string pathVecToStrDirectionsTemp(vector<State<Cell, double> *> &solutionVector);


int main(int argc, char *argv[]) {
    /* P = ISearchable<Cell, double>*
     * S = vector<State<Cell, double> *>
     * T = Cell
     * C = double
     * */
    vector<vector<double>> values = {{0,1,2,3},
                                     {4,5,6,7},
                                     {8,9,10,11},
                                     {12,13,14,15}};
    string problemStr = "@0,1,2,3@4,5,6,7@8,9,10,11@12,13,14,15~0,0~3,3";
    Cell c1 = Cell(0, 0);
    auto *s = new State<Cell, double>(c1);
    Cell c2 = Cell(3, 3);
    auto *e = new State<Cell, double>(c2);
    ISearchable<Cell, double> *matrix = new Matrix(4, 4, values, s, e);

    ISearcher<vector<State<Cell, double> *>, Cell, double> *b = new BreadthFirstSearch<Cell, double>();
    Solver<ISearchable<Cell, double> *, vector<State<Cell, double> *>> *solver = new
            SolverSearcherAdapter<vector<State<Cell, double> *>, Cell, double>(b);
    CacheManager<string, string>* cacheManager = new FileCacheManager();

    bool checkResult = cacheManager->isSaved(problemStr);
    if (checkResult) {
        //converts solution to string in order to send it to the client
        string solution = cacheManager->getSolution(problemStr);
        cout << solution << endl;
    } else {
        vector<State<Cell, double> *> solutionV = solver->solve(matrix);
        string solution=pathVecToStrDirectionsTemp(solutionV);
        cacheManager->saveSolution(problemStr, solution);
    }
    delete (cacheManager);
}

string pathVecToStrDirectionsTemp(vector<State<Cell, double> *> &solutionVector){
    int iCurrent=solutionVector.at(0)->getState().getI();
    int jCurrent=solutionVector.at(0)->getState().getJ();
    string directions;
    for(auto current=solutionVector.begin();current!=solutionVector.end();current++){
        int iNext=(*current)->getState().getI();
        int jNext=(*current)->getState().getJ();
        if(iCurrent<iNext){ // below row- Down
            directions+="Down,";
        }else if(iCurrent>iNext){ //above row - Up
            directions+="Up,";
        }else if(jCurrent<jNext){ //right Cell - Right
            directions+="Right,";
        }else if(jCurrent>jNext){ //left Cell - Left
            directions+="Left,";
        }
        iCurrent=iNext;
        jCurrent=jNext;
    }
    directions.erase(directions.length()-1,1); // delete last ','
    return directions;
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
