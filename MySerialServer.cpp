/**
 * Serial Server - Server who can deal with one client at a time
 */
#include "MySerialServer.h"
#include <netinet/in.h>
#include <cstdio>
#include <strings.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <iostream>

void MySerialServer::open(int port, ClientHandler *clientHandler) {
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
        //handle client, when finished, move on to the next client.
        this->clientHandler->handleClient(newSocketFd);
    }
    cout<<"server closed"<<endl;
    close(socketFd);
}
