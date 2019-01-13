#ifndef PROJECT2_MYPARALLELSERVER_H
#define PROJECT2_MYPARALLELSERVER_H

#include "AbstractServer.h"

using namespace server_side;

/**
 * Parallel Server - Server who can deal with one client at a time
 */
class MyParallelServer : public AbstractServer {
public:
    //opens the server
    virtual void open(int port, ClientHandler *clientHandler);
};


#endif //PROJECT2_MYPARALLELSERVER_H
