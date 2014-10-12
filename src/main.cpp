#include <iostream>

#include "agdyne.h"

using namespace agdyne;

int main(int argc, char *argv[]) {
    // Default database location.
    std::string db_location = "/tmp";

    for (int i = 0; i < argc; i++) {
        std::string arg = argv[i];

        if (arg[0] == '-') {
            std::string param = arg.substr(1);
            if (param == "d" || param == "-db") {
                i++;
                db_location = argv[i];
            }
        }
    }

    GraphServer gServer(1978, db_location);
    gServer.start();
    return 0;
}
