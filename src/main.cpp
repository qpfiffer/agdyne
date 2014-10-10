#include <iostream>

#include "agdyne.h"

using namespace agdyne;

int main(int argc, char *argv[]) {
    GraphServer gServer(1978);
    gServer.start();
    return 0;
}
