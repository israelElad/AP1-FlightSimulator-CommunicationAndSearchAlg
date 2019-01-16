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
    bool firstConnection= true;

    while (!shouldStop) {
        newSocketFd = accept(socketFd,  (struct sockaddr *) &cli_addr, (socklen_t *) &clientLen);
        if (newSocketFd < 0)	{
            if (errno == EWOULDBLOCK)	{
                if(firstConnection){
                    cout << "first Client- checking shouldStop and waiting again." << endl;
                    continue;
                }
                cout << "timeout!" << endl;
                break;
            }	else	{
                perror("other error");
                break;
            }
        }
        firstConnection=false;
        cout<<"connected"<<endl;
        //handle client, when finished, move on to the next client.
        this->clientHandler->handleClient(newSocketFd);
    }
    cout<<"server closed"<<endl;
    close(socketFd);
}

