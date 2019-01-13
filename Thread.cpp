#include <pthread.h>
#include <iostream>
#include "Thread.h"

void Thread::start() {
    pthread_t tId;
    // Launch a thread
    pthread_create(&tId, nullptr, threadFunc, this->runnable);
//    std::cout<<"thread stopped"<<std::endl;
}

Thread::Thread(Runnable *runnable) {
    this->runnable = runnable;
}

void *Thread::threadFunc(void *runnable) {
    Runnable *r;
    r = static_cast<Runnable *>(runnable);
    r->run();
    return nullptr;
}

void Thread::stop() {
    this->runnable->stop();
}




