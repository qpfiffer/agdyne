#include "agdyne.h"
#include "graph.h"
#include "server.h"
using namespace agdyne;

GraphServer::GraphServer(const int port): TCPServer(port) {
}

//GraphServer::~GraphServer() {
//}
