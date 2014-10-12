#include "agdyne.h"
using namespace agdyne;

GraphServer::GraphServer(const int port, const std::string db_location):
    TCPServer(port), graph(db_location) {
}

//GraphServer::~GraphServer() {
//}

void GraphServer::return_ok(const int sock_fd) {
    ::write(sock_fd, (char *)AG_OK, sizeof(AG_ERR));
}

void GraphServer::return_err(const int sock_fd) {
    ::write(sock_fd, (char *)AG_ERR, sizeof(AG_ERR));
}

void GraphServer::work() {
    ::printf("Thread started.\n");

    bool quit = false;
    while(!quit) {
        struct sockaddr_in their_addr_in;
        socklen_t their_addr_size;

        their_addr_size = sizeof(their_addr_in);
        int client_fd = ::accept(_sock_fd, (struct sockaddr *)&their_addr_in, &their_addr_size);
        ::printf("Connection receieved.\n");

        while (true) {
            char magic = 0xFF;
            int rc = recv(client_fd, &magic, 1, 0);
            if (rc == 0) // Socket closed.
                close(client_fd);

            ::printf("Receieved %c\n", magic);
            switch (magic) {
                case AG_OK:
                    return_ok(client_fd);
                case AG_START_TX:
                    return_err(client_fd);
                case AG_COMMIT_TX:
                    return_err(client_fd);
                case AG_ABORT_TX:
                    return_err(client_fd);
                case AG_QUIT:
                    close(client_fd);
                default:
                    return_err(client_fd);
            }
        }
    }
}
