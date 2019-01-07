//
// Created by elad on 07/01/19.
//

#ifndef PROJECT2_THREAD_H
#define PROJECT2_THREAD_H


#include "Runnable.h"

class Thread {
private:
    Runnable *runnable;
public:
    static void* threadFunc(void* n);
    Thread(Runnable *runnable);
    void start();
};


#endif //PROJECT2_THREAD_H
