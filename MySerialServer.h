#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"
#include "Thread.h"

using namespace server_side;

/**
 * Serial Server - Server who can deal with one client at a time
 */
class MySerialServer : public Server {
private:
    Thread thread= nullptr;
public:
    //opens the server
    virtual void open(int port, ClientHandler *clientHandler);

    //stop the server
    virtual void stop();
};


#endif //PROJECT2_MYSERIALSERVER_H
