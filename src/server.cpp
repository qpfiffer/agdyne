#include "server.h"

using namespace agdyne;

TCPServer::TCPServer(const int port): _workers{0}, _sock_fd(-1) {
    // Thank you Based Beej
    this->_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (this->_sock_fd < 0) {
        FailedToInit ex;
        throw ex;
    }

    struct sockaddr_in hints = {
        .sin_family         = AF_INET,
        .sin_port           = htons(port),
        .sin_addr.s_addr    = htonl(INADDR_LOOPBACK)
    };

    int rc = ::bind(_sock_fd, (struct sockaddr *)&hints, sizeof(hints));
    if (rc < 0) {
        FailedToInit ex;
        throw ex;
    }

    rc = ::listen(_sock_fd, 10);
    if (rc < 0) {
        FailedToInit ex;
        throw ex;
    }
}

void TCPServer::start() {
}

void TCPServer::work() {
}

TCPServer::~TCPServer() {
    if (_sock_fd != -1)
        close(_sock_fd);
}
