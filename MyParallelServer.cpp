/**
 * Parallel Server - Server who can deal with one client at a time
 */
#include "MyParallelServer.h"
#include <netinet/in.h>
#include <cstdio>
#include <strings.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <iostream>
#include <thread>

void MyParallelServer::open(int port, ClientHandler *clientHandler) {
    this->port=port;
    this->clientHandler=clientHandler;
    setUpServer();

    while (!shouldStop) {
        newSocketFd = accept(socketFd,  (struct sockaddr *) &cli_addr, (socklen_t *) &clientLen);
        if (newSocketFd < 0)	{
            if (errno == EWOULDBLOCK)	{
                cout << "timeout!" << endl;
                continue;
            }	else	{
                perror("other error");
                continue;
            }
        }
        cout<<"connected"<<endl;
        thread serverThread(&ClientHandler::handleClient,this->clientHandler,newSocketFd);
        serverThread.detach();

    }
    cout<<"server closed"<<endl;
    close(socketFd);
}