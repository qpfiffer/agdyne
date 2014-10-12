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
    int rc = sp_begin(_sp_env.db);
}

bool Graph::commit_tx() {
}

bool Graph::abort_tx() {
}

