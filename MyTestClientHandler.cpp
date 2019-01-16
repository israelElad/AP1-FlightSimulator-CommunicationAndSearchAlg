#include <sys/socket.h>
#include <iostream>
#include <cstring>
#include <unistd.h>
#include "MyTestClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"


MyTestClientHandler::MyTestClientHandler(Solver<string, string> *solver, CacheManager<string, string> *cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

void MyTestClientHandler::handleClient(int newSocketFd) {
    cout<<"entered handle client"<<endl;
    string buffer=readLineFromSocket(newSocketFd);
    cout<<"after readline"<<endl;

    while (strcmp(buffer.c_str(), "end") != 0) {
        bool checkResult = this->cacheManager->isSaved(buffer);
        if (checkResult) {
            //converts solution to string in order to send it to the client
            string solution = this->cacheManager->getSolution(buffer);
            send(newSocketFd, solution.c_str(), solution.length(), 0);
        } else {
            string solution = this->solver->solve(buffer);
            this->cacheManager->saveSolution(buffer, solution);
            send(newSocketFd, solution.c_str(), solution.length(), 0);
        }
        buffer=readLineFromSocket(newSocketFd);
    }
    //close client socket
    close(newSocketFd);
}

string MyTestClientHandler::readLineFromSocket(int newSocketFd) {
    //read line into buffer
    char buffer[1024];
    int n = 0;
    char c = 'n';
    int idx = 0;
    while (true)   {
        n = static_cast<int>(read(newSocketFd, &c, 1));
        if (n < 0) {
            if(errno == EWOULDBLOCK){
                cout<<"reading timeout, trying again"<<endl;
                continue;
            }
            perror("ERROR reading from socket");
            return nullptr;
        }   else if (n == 0)    {
            perror("Socket is closed");
            return nullptr;
        }
        if(c == '\n'){
            break;
        }
        buffer[idx++] = c;
    }
    buffer[idx] = 0;
    return buffer;
}
