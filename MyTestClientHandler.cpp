#include "MyTestClientHandler.h"


MyTestClientHandler::MyTestClientHandler(Solver<string, string> *solver, CacheManager *cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

void MyTestClientHandler::handleClient(int newSocketFd) {
    string buffer=readLineFromSocket(newSocketFd);

    while (strcmp(buffer.c_str(), "end") != 0) {
        bool checkResult = this->cacheManager->isSaved(buffer);
        if (checkResult) {
            //converts solution to string in order to send it to the client
            string solution = this->cacheManager->getSolution(buffer);
            send(newSocketFd, solution.c_str(), solution.length(), 0);
        } else {
            string solution = this->solver->solve(buffer);
            this->cacheManager->saveSolution(buffer, solution);
        }
//        fflush(ostream1); todo
        buffer=readLineFromSocket(newSocketFd);
    }
}

string MyTestClientHandler::readLineFromSocket(int newSocketFd) {
    //todo: improve if there is time
//    std::string line;
//    char buf[1024];
//    int n = 0;
//        while(n = read(newSocketFd, buf, 1024))
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
    while (true)   {
        n = static_cast<int>(read(newSocketFd, &c, 1));
        if (n < 0) {
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
