/**
 * Serial Server - Server who can deal with one client at a time
 */
#include "MySerialServer.h"
#include "Thread.h"
#include "OpenServerTask.h"
#include "RunnableTask.h"

void MySerialServer::open(int port, ClientHandler *clientHandler) {
    //creates thread will run a runnable task which is OpenServerTask
    this->thread=Thread(new RunnableTask(new OpenServerTask(port,clientHandler)));
    //start running the server
    this->thread.start();

}

void MySerialServer::stop() {
 this->thread.stop();
}
