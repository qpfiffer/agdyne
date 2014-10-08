#pragma once
#include <exception>
#include "sophia.h"

namespace agdyne {
    class Node;

    typedef void* SOPHIA_ENV;

    class Graph {
        class FailedToInit: public std::exception {
            virtual const char *what() const throw() {
                return "Failed to initialize Graph.";
            }
        };
        public:
            Graph();
            ~Graph();
            bool addNode(Node *node);
            void addEdge(Node *from, Node *to, const std::string &label);

            // Utility functions:
            void printEdges() const;
            void printNodes() const;
            void printSigmaGraphJS() const;
            void printCSV() const;

            // Helper stuff
            const size_t getNodeCount();
            const size_t getEdgeCount();
        private:
            SOPHIA_ENV _sp_env;
    };
}
