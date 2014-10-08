#pragma once
#include <exception>
#include <string>

#include "server.h"
#include "graph.h"

namespace agdyne {
    class GraphServer: public TCPServer {
        public:
            GraphServer(const int port);
        private:
            Graph graph;
    };
}
