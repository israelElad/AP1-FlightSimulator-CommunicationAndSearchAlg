#ifndef PROJECT2_ABSTRACTSERVER_H
#define PROJECT2_ABSTRACTSERVER_H

#include "ClientHandler.h"
#include "Server.h"
#include <netinet/in.h>
#include <cstdio>
#include <strings.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <iostream>


namespace server_side {

    class AbstractServer :public Server{
    protected:
        bool shouldStop=false;
        int port=0;
        ClientHandler *clientHandler= nullptr;
        int socketFd=0, newSocketFd=0, clientLen=0;
        struct sockaddr_in serv_addr{}, cli_addr{};

    public:
        // open the server and wait for clients
        virtual void open(int port, ClientHandler *clientHandler) = 0;

        // close the server
        virtual void stop(){
            cout<<"shouldStop=";
            this->shouldStop=true;
            cout<<shouldStop<<endl;
        }

        void setUpServer(){

            cout<< "bla"<<endl;

            cout<< "in while"<<endl;
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

            /* Now start listening for the clients, here process will go in sleep mode and
             * will wait for the incoming connection */
            listen(socketFd, 5);
            clientLen = sizeof(cli_addr);

            timeval timeout;
            timeout.tv_sec = 3;
            //todo: change to 1
            timeout.tv_usec = 0;

            setsockopt(socketFd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));
        }

        virtual ~AbstractServer(){

        }
    };
}
#endif //PROJECT2_ABSTRACTSERVER_H
