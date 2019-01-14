#include "MyClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Cell.h"
#include "State.h"
#include "Matrix.h"
#include <string>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include <sstream>
#include <sys/socket.h>
#include "ISearcher.h"
#include "BestFirstSearch.h"

using namespace std;

MyClientHandler::MyClientHandler(Solver<ISearchable<Cell, double> *, vector<State<Cell, double> *>> *solver,
                                 CacheManager<string, string> *cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

void MyClientHandler::handleClient(int newSocketFd) {
    cout << "entered handle client" << endl;
    string buffer = readLineFromSocket(newSocketFd);
    cout << "after readline" << endl;

    vector<string> dataFromClient;

    // put all the data from the client in a vector
    while (strcmp(buffer.c_str(), "end") != 0) {
        dataFromClient.push_back(buffer);
        buffer = readLineFromSocket(newSocketFd);
    }

    unsigned long vectorSize = dataFromClient.size();
    unsigned long numOfMatrixRows = vectorSize - 2;
    unsigned long numOfMatrixColumns = 0;

    string problemStr;

    // create vector with all the rows of the matrix
    vector<vector<double>> values;
    for (int i = 0; i < numOfMatrixRows; ++i) {
        string row = dataFromClient.at(static_cast<unsigned long>(i));
        problemStr.append("@" + row); // "@" marks the beginning of matrix row
        vector<double> separated = this->separateDoublesByComma(row);
        values.push_back(separated);
        if (i == 0) {
            numOfMatrixColumns = separated.size();
        }
    }

    // create start state
    string startStr = dataFromClient.at(numOfMatrixRows);
    problemStr.append("~" + startStr); // "~" marks the beginning of start state
    vector<double> startStrSeparated = this->separateDoublesByComma(startStr);
    int i1 = static_cast<int>(startStrSeparated.at(0));
    int j1 = static_cast<int>(startStrSeparated.at(1));
    Cell c1 = Cell(i1, j1);
    auto *s = new State<Cell, double>(c1);

    // create exit state
    string exitStr = dataFromClient.at(numOfMatrixRows + 1);
    problemStr.append("~" + exitStr); // "~" marks the beginning of exit state
    vector<double> exitStrSeparated = this->separateDoublesByComma(exitStr);
    int i2 = static_cast<int>(startStrSeparated.at(0));
    int j2 = static_cast<int>(startStrSeparated.at(1));
    Cell c2 = Cell(i2, j2);
    auto *e = new State<Cell, double>(c2);

    // create the matrix
    ISearchable<Cell, double> *matrix = new Matrix(static_cast<int>(numOfMatrixRows),
                                                   static_cast<int>(numOfMatrixColumns), values, s, e);

    bool checkResult = this->cacheManager->isSaved(problemStr);
    if (checkResult) {
        //converts solution to string in order to send it to the client
        string solution = this->cacheManager->getSolution(problemStr);
        send(newSocketFd, solution.c_str(), solution.length(), 0);
    } else {
        vector<State<Cell, double> *> solutionV = this->solver->solve(matrix);
        string solution=pathVecToStrDirections(solutionV);
        this->cacheManager->saveSolution(problemStr, solution);
        send(newSocketFd, solution.c_str(), solution.length(), 0);
    }

    //close client socket
    close(newSocketFd);
}

// reading line from socket
string MyClientHandler::readLineFromSocket(int newSocketFd) {
    cout << "in readline" << endl;

    //read line into buffer
    char buffer[1024];
    int n = 0;
    char c = 'n';
    int idx = 0;
    while (true) {
        n = static_cast<int>(read(newSocketFd, &c, 1));
        if (n < 0) {
            if (errno == EWOULDBLOCK) {
                cout << "reading timeout, trying again" << endl;
                continue;
            }
            perror("ERROR reading from socket");
            return nullptr;
        } else if (n == 0) {
            perror("Socket is closed");
            return nullptr;
        }
        if (c == '\n') {
            break;
        }
        buffer[idx++] = c;
    }
    buffer[idx] = 0;
    return buffer;
}

// separate by commas
vector<double> MyClientHandler::separateDoublesByComma(string &row) {
    // replace ' , ' by ' '
    replace(row.begin(), row.end(), ',', ' ');
    vector<double> separated;
    stringstream ss(row);
    double value;
    while (ss >> value) {
        separated.push_back(value);
    }
    return separated;
}

string MyClientHandler::pathVecToStrDirections(vector<State<Cell, double> *> &solutionVector){
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
