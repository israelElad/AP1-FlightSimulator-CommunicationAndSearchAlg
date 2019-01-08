/**
 * read line by line from socket(until "end" was read) and deal with each line.
 */
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <sys/socket.h>
#include "MyTestClientHandler.h"

using namespace std;

template<typename P, typename S>
MyTestClientHandler<P, S>::MyTestClientHandler(const Solver<P, S> &solver, const CacheManager<P, S> &cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

template<typename P, typename S>
void MyTestClientHandler<P, S>::handleClient(int socketFd) {

    string buffer=readLineFromSocket(socketFd);


    while (strcmp(buffer.c_str(), "end") != 0) {
        bool checkResult = this->cacheManager.isSaved(buffer);
        if (checkResult) {
            //converts solution to string in order to send it to the client
            string solution = this->cacheManager.getSolution(buffer);
            send(socketFd, solution.c_str(), solution.length(), 0);
        } else {
            S solution = this->solver.solve(buffer);
            this->cacheManager.saveSolution(buffer, solution);
        }
//        flush(ostream1); todo
        buffer=readLineFromSocket(socketFd);
    }
}

template<typename P, typename S>
string MyTestClientHandler<P, S>::readLineFromSocket(int socketFd) {
    //todo: improve if there is time
//    std::string line;
//    char buf[1024];
//    int n = 0;
//        while(n = read(newSockFd, buf, 1024))
//        {
//            size_t pos = std::find(buf, buf + n, '\n');
//            if(pos != std::string::npos)
//            {
//                if (pos < 1024-1 && buf[pos + 1] == '\n')
//                    break;
//            }
//            line += buf;
//        }
//
//        line += buf;


    //read line into buffer
    char buffer[1024];
    int n = 0;
    char c = 'n';
    int idx = 0;
    while (c != '\n')   {
        n = static_cast<int>(read(socketFd, &c, 1));
        if (n < 0) {
            perror("ERROR reading from socket");
            return nullptr;
        }   else if (n == 0)    {
            perror("Socket is closed");
            return nullptr;
        }
        buffer[idx++] = c;
    }
    buffer[idx] = 0;
    return buffer;
}

template class MyTestClientHandler<string,string>;

