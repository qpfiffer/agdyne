#pragma once
#include <exception>
#include <sys/socket.h>
#include <unistd.h>

namespace agdyne {
    class TCPServer {
        class FailedToInit: public std::exception {
            virtual const char *what() const throw() {
                return "Failed to initialize TCPServer.";
            }
        };
        public:
            TCPServer(const int port);
            ~TCPServer();
        private:
            int sock_fd;
    };
}
