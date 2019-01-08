// Determining the type and handling of the call with the customer

#ifndef PROJECT2_CLIENTHANDLER_H
#define PROJECT2_CLIENTHANDLER_H

#include <istream>

using namespace std;

class ClientHandler {
public:
    // from istream1 we read the client messages and to ostream1 we write the answers of the server
    virtual void handleClient(istream istream1, ostream ostream1) = 0;
};

#endif //PROJECT2_CLIENTHANDLER_H
