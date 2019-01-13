#ifndef PROJECT2_SERVER_H
#define PROJECT2_SERVER_H

#include <iostream>
#include "ClientHandler.h"

namespace server_side {

    class Server {
    public:
        // open the server and wait for clients
        virtual void open(int port, ClientHandler *clientHandler) = 0;

        // close the server
        virtual void stop()=0;
    };
}


#endif //PROJECT2_SERVER_H
