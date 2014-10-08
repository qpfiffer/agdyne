#include "server.h"

using namespace agdyne;

TCPServer::TCPServer(const int port): sock_fd(-1) {
    // Thank you Based Beej
    this->sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (this->sock_fd < 0) {
        FailedToInit ex;
        throw ex;
    }

    struct sockaddr_in hints = {
        .sin_family         = AF_INET,
        .sin_port           = htons(port),
        .sin_addr.s_addr    = htonl(INADDR_LOOPBACK)
    };

    int rc = ::bind(sock_fd, (struct sockaddr *)&hints, sizeof(hints));
    if (rc < 0) {
        FailedToInit ex;
        throw ex;
    }
}

TCPServer::~TCPServer() {
    if (sock_fd != -1)
        close(sock_fd);
}
