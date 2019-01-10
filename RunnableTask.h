/**
 * RunnableTask - a task that can be run
 */

#ifndef PROJECT2_RUNNABLETASK_H
#define PROJECT2_RUNNABLETASK_H


#include "Runnable.h"
#include "Task.h"

class RunnableTask: public Runnable {
private:
    Task* task;
public:
    explicit RunnableTask(Task* task);
    //run task
    virtual void run();
    virtual void stop();
};


#endif //PROJECT2_RUNNABLETASK_H
