#include "Main.h"
#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

using namespace boot;

template<typename P, typename S>
int boot::Main::main(int argc, char *argv) {

    Solver<P, S> *solver = new StringReverser<P, S>();
    CacheManager<P, S> *cacheManager = new FileCacheManager<P, S>();
    ClientHandler *clientHandler = MyTestClientHandler<P, S>(solver, cacheManager);
    int port = argv[0];
    Server *server = new MySerialServer();
    server->open(port, cacheManager);

    return 0;
}
