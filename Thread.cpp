//
// Created by elad on 07/01/19.
//

#include <pthread.h>
#include "Thread.h"

void Thread::start() {
    pthread_t tId;
    // Launch a thread
    pthread_create(&tId, nullptr, threadFunc, this->runnable);
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




