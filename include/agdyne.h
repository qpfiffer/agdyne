#pragma once
#include <exception>
#include <string>

#include "server.h"
#include "graph.h"

#define AG_START_TX 0x40
#define AG_COMMIT_TX 0x41
#define AG_ABORT_TX 0x42

#define AG_OK 0x50
#define AG_ERR 0x51
#define AG_QUIT 0x52

namespace agdyne {
    class GraphServer: public TCPServer {
        public:
            GraphServer(const int port, const std::string db_location);
            void work();
        private:
            void return_ok(const int sock_fd);
            void return_err(const int sock_fd);
            Graph graph;
    };
}
