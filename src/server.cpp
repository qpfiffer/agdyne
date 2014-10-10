#include "server.h"
#include <string>

using namespace agdyne;

TCPServer::TCPServer(const int port): _workers(), _sock_fd(-1) {
    // Thank you Based Beej
    this->_sock_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (this->_sock_fd < 0) {
        FailedToInit ex;
        throw ex;
    }

    struct sockaddr_in hints = {0};
    hints.sin_family         = AF_INET;
    hints.sin_port           = htons(port);
    hints.sin_addr.s_addr    = htonl(INADDR_LOOPBACK);

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
    ::printf("Listening on %i.\n", port);
}

TCPServer::~TCPServer() {
    if (_sock_fd != -1)
        close(_sock_fd);
}

void TCPServer::start() {
    // Start up all worker threads
    for (int i = 0; i < DEFAULT_SERVER_THREAD_NUM; i++) {
        this->_workers[i] = std::thread(&TCPServer::work, this);
    }

    // Now just sit and spin until we're done.
    for (int i = 0; i < DEFAULT_SERVER_THREAD_NUM; i++) {
        this->_workers[i].join();
    }

}

void TCPServer::work() {
    ::printf("Thread started.\n");

    bool quit = false;
    while(!quit) {
        struct sockaddr_in their_addr_in;
        socklen_t their_addr_size;
        their_addr_size = sizeof(their_addr_in);
        int client_fd = ::accept(_sock_fd, (struct sockaddr *)&their_addr_in, &their_addr_size);
        ::printf("Connection receieved.\n");
        close(client_fd);
    }
}

