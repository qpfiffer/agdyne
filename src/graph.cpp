#include "agdyne.h"
#include "graph.h"
using namespace agdyne;

Graph::Graph(const std::string db_location) {
}

Graph::~Graph() {
}

bool Graph::start_tx() {
    /*
    if (current_tx_)
        return false;

    void *tx = sp_begin(_sp_env);

    if (!tx)
        return false;

    this->_current_tx = tx;
    return true;
    */
    return false;
}

bool Graph::commit_tx() {
    return false;
}

bool Graph::abort_tx() {
    return false;
}

