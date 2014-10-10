#pragma once
#include <arpa/inet.h>
#include <exception>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

#define DEFAULT_SERVER_THREAD_NUM 2

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

            void start();
            void work();

            virtual bool process() = 0;
        private:
            std::thread *_workers[DEFAULT_SERVER_THREAD_NUM];
            int _sock_fd;
    };
}
