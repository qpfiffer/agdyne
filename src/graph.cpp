#include "agdyne.h"
#include "graph.h"
using namespace agdyne;

Graph::Graph() {
    this->_sp_env = sp_env();
    if (!this->_sp_env) {
        FailedToInit ex;
        throw ex;
    }
}

Graph::~Graph() {
}
