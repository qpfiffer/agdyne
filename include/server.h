#pragma once
#include <arpa/inet.h>
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

            virtual bool process() = 0;
        private:
            int sock_fd;
    };
}
