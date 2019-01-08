#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

using namespace std;


int main(int argc, char *argv[]) {
    Solver<string, string> *solver = new StringReverser<string, string>();
    CacheManager<string, string> *cacheManager = new FileCacheManager<string, string>();
    ClientHandler *clientHandler = MyTestClientHandler<string, string>(solver, cacheManager);
    int port = argv[0];
    Server *server = new MySerialServer();
    server->open(port, clientHandler);

    return 0;
}



//todo
//
//namespace boot {
//    class Main {
//    public:
//        template<typename P, typename S>
//        int mainProgram(int argc, char *argv) {
//
//            Solver<P, S> *solver = new StringReverser<P, S>();
//            CacheManager<P, S> *cacheManager = new FileCacheManager<P, S>();
//            ClientHandler *clientHandler = MyTestClientHandler<P, S>(solver, cacheManager);
//            int port = argv[0];
//            Server *server = new MySerialServer();
//            server->open(port, clientHandler);
//
//            return 0;
//        }
//    };
//}
//
//using namespace boot;
//
//int main(int argc, char* argv[]){
//    Main m;
//    return m.mainProgram<string,string>(argc,*argv);
//}