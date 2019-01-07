#ifndef PROJECT2_MYSERIALSERVER_H
#define PROJECT2_MYSERIALSERVER_H

#include "Server.h"

using namespace server_side;

class MySerialServer : public Server {
    virtual void open(int port, ClientHandler clientHandler);

    virtual void stop();
};


#endif //PROJECT2_MYSERIALSERVER_H
