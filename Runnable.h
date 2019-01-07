/**
 * Runnable - something that can be run
 * A type of class (Runnable is an Interface) that can be put into a thread,
 * describing what the thread is supposed to do.
 */

#ifndef PROJECT2_RUNNABLE_H
#define PROJECT2_RUNNABLE_H


class Runnable {
public:
    virtual void run()=0;
};


#endif //PROJECT2_RUNNABLE_H
