#include "agdyne.h"
#include "graph.h"
using namespace agdyne;

Graph::Graph(const std::string db_location) {
    // Initialize Sophia env
    this->_sp_env = sp_env();
    if (!this->_sp_env) {
        FailedToInit ex;
        throw ex;
    }

    void *rt = sp_ctl(this->_sp_env, db_location.c_str());
    if (!rt) {
        FailedToInit ex;
        throw ex;
    }

    int rc = sp_open(this->_sp_env);
    if (rc == -1) {
        FailedToInit ex;
        throw ex;
    }

}

Graph::~Graph() {
    sp_destroy(this->_sp_env);
}

bool Graph::start_tx() {
    if (_current_tx)
        return false;

    void *tx = sp_begin(_sp_env);

    if (!tx)
        return false;
    this->_current_tx = tx;
    return true;
}

bool Graph::commit_tx() {
    return false;
}

bool Graph::abort_tx() {
    return false;
}

