//
// Created by elad on 07/01/19.
//

#include "RunnableTask.h"
#include "Task.h"

RunnableTask::RunnableTask(Task* task) {
    this->task=task;
}


void RunnableTask::run() {
    this->task->doTask();
}
