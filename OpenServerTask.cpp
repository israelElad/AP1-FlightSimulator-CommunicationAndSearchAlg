/**
 * A task which opens a server
 */

#include <netinet/in.h>
#include <cstdio>
#include <strings.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include "OpenServerTask.h"

using namespace std;

OpenServerTask::OpenServerTask(int port) {
    this->port=port;
}

void OpenServerTask::doTask() {
    int socketFd, newSockFd, clientLen;
    char buffer[1024];
    struct sockaddr_in serv_addr{}, cli_addr{};
    // First call to socket() function
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd < 0) {
        perror("ERROR opening socket");
        return;
    }
    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(static_cast<uint16_t>(this->port));
    // Now bind the host address using bind() call
    if (bind(socketFd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        return;
    }

    /* Now start listening for the clients, here process will go in sleep mode and
     * will wait for the incoming connection */
    listen(socketFd, 5);
    clientLen = sizeof(cli_addr);
    // Accept actual connection from the client
    newSockFd = accept(socketFd, (struct sockaddr *) &cli_addr, (socklen_t *) &clientLen);
    if (newSockFd < 0) {
        perror("ERROR on accept");
        return;
    }
    std::string line;
    char buf[1024];
    int n = 0;
    //TODO:shouldStop
    while (shouldStop == false) {
        while(n = read(newSockFd, buf, 1024))
        {
            size_t pos = std::find(buf, buf + n, '\n');
            if(pos != std::string::npos)
            {
                if (pos < 1024-1 && buf[pos + 1] == '\n')
                    break;
            }
            line += buf;
        }

        line += buf;

//        char c = 'n';
//        int idx = 0;
//        while (c != '\n')   {
//            n = static_cast<int>(read(newSockFd, &c, 1));
//            if (n < 0) {
//                perror("ERROR reading from socket");
//                return;
//            }   else if (n == 0)    {
//                perror("Socket is closed");
//                return;
//            }
//            buffer[idx++] = c;
//        }
//        buffer[idx] = 0;
    }
}

