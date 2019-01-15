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
#include "DepthFirstSearch.h"
#include "AStar.h"

using namespace std;

string pathVecToStrDirectionsTemp(vector<State<Cell, double> *> &solutionVector);


int main(int argc, char *argv[]) {
    /* P = ISearchable<Cell, double>*
     * S = vector<State<Cell, double> *>
     * T = Cell
     * C = double
     * */
    vector<vector<double>> values = {{10,1,7},
                                     {2,3,13},
                                     {4,8,9}};
    string problemStr = "@10,1,7@2,3,13@4,8,9~0,0~2,2";
    Cell c1 = Cell(0, 0);
    auto *s = new State<Cell, double>(c1);
    Cell c2 = Cell(2, 2);
    auto *e = new State<Cell, double>(c2);
    ISearchable<Cell, double> *matrix = new Matrix(3, 3, values, s, e);

    ISearcher<vector<State<Cell, double> *>, Cell, double> *b = new AStar<Cell, double>();
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
        cout << solution << endl;
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
