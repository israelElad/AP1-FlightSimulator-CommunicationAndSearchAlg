//
// Created by elad on 07/01/19.
//

#ifndef PROJECT2_OPENSERVERTASK_H
#define PROJECT2_OPENSERVERTASK_H


#include "Task.h"

/**
 * A task which opens a server
 */
class OpenServerTask: public Task {
    bool shouldStop=false;
    int port;
public:
    explicit OpenServerTask(int port);
    void doTask();
};


#endif //PROJECT2_OPENSERVERTASK_H
