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

void GraphServer::process_binary(const int client_fd) {
    uint8_t buf[255] = {0};
    int rc = recv(client_fd, &buf, 255, 0);
    if (rc == 0)
        close(client_fd);

    /*
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
    */
}

void GraphServer::process_ascii(const int sock_fd, char first_byte) {
    return_ok(sock_fd);
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
            char magic = 0;
            // magic >= 0x80 then we are in binary mode, otherwise
            // we're just doing real queries in ASCII.
            int rc = recv(client_fd, &magic, 1, 0);
            if (rc == 0 || magic < 0)
                close(client_fd);

            ::printf("Received %c\n", magic);
            if (magic >= 0x80) {
                this->process_binary(client_fd);
            } else {
                this->process_ascii(client_fd, magic);
            }
        }
    }
}
