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
            virtual void work() = 0;
        private:
            void shutdown();
            std::thread _workers[DEFAULT_SERVER_THREAD_NUM];
        protected:
            int _sock_fd;
    };
}
