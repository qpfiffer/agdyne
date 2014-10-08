#include "server.h"

using namespace agdyne;

TCPServer::TCPServer(const int socket): sock_fd(-1) {
    this->sock_fd = ::socket(PF_INET, SOCK_STREAM, 0);
    if (this->sock_fd < 0) {
        FailedToInit ex;
        throw ex;
    }
}

TCPServer::~TCPServer() {
    if (sock_fd != -1)
        close(sock_fd);
}
