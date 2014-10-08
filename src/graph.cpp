#include "agdyne.h"
#include "graph.h"
using namespace agdyne;

Graph::Graph() {
    // Initialize Sophia env
    this->_sp_env = sp_env();
    if (!this->_sp_env) {
        FailedToInit ex;
        throw ex;
    }

    void *rt = sp_ctl(this->_sp_env);
    if (!rt) {
        FailedToInit ex;
        throw ex;
    }

}

Graph::~Graph() {
    sp_destroy(this->_sp_env);
}
