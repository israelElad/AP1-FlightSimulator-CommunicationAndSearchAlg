//
// Created by elad on 07/01/19.
//

#ifndef PROJECT2_OPENSERVERTASK_H
#define PROJECT2_OPENSERVERTASK_H


#include "Task.h"
#include "ClientHandler.h"

/**
 * A task which opens a server
 */
class OpenServerTask: public Task {
    bool shouldStop=false;
    int port;
    ClientHandler *clientHandler;
public:
    explicit OpenServerTask(int port,ClientHandler *clientHandler);
    void doTask();
    void stopTask();
};


#endif //PROJECT2_OPENSERVERTASK_H
