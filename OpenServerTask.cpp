/**
 * A task which opens a server that listen to a port, and when a client connects, activate clientHandler.
 */

#include <netinet/in.h>
#include <cstdio>
#include <strings.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <iostream>
#include "OpenServerTask.h"

using namespace std;

OpenServerTask::OpenServerTask(int port,ClientHandler *clientHandler) {
    this->port=port;
    this->clientHandler=clientHandler;
}

void OpenServerTask::doTask() {
    cout<< "bla"<<endl;

    cout<< "in while"<<endl;
    int socketFd, newSocketFd, clientLen;
    struct sockaddr_in serv_addr{}, cli_addr{};
    int n;
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

    //todo: interval

    /* Now start listening for the clients, here process will go in sleep mode and
     * will wait for the incoming connection */
    listen(socketFd, 5);
    clientLen = sizeof(cli_addr);

    timeval timeout;
    timeout.tv_sec = 3;
    timeout.tv_usec = 0;

    setsockopt(socketFd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    //    //TODO:shouldStop
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

        this->clientHandler->handleClient(newSocketFd);
        close(newSocketFd);
    }
    cout<<"server closed"<<endl;
    close(socketFd);

}

void OpenServerTask::stopTask() {
    cout<<"shouldStop=";
    this->shouldStop=true;
    cout<<shouldStop<<endl;
}

