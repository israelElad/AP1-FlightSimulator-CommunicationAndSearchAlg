#include "MySerialServer.h"
#include "MyTestClientHandler.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

using namespace std;

int main(int argc, char *argv[]) {
    Solver<string, string> *solver = new StringReverser();
    CacheManager *cacheManager = new FileCacheManager();
    ClientHandler *clientHandler = new MyTestClientHandler(solver, cacheManager);
    int port = stoi(argv[1]);
    Server *server = new MySerialServer();
    server->open(port, clientHandler);
    cout<<"opened"<<endl;
//    server->stop();
//    cout<<"stop server"<<endl;
//    sleep(500);
//    cout<<"after stop server"<<endl;
    while(true){}
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