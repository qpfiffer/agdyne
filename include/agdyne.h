#pragma once
#include <exception>
#include <string>

extern "C" {
#include "sophia.h"
}

namespace agdyne {
    typedef void* SOPHIA_ENV;

    class FailedToInit: public std::exception {
        virtual const char *what() const throw() {
            return "Failed to initialize Graph.";
        }
    };
}
