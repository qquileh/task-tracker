#include <iostream>
#include "../include/CLArgs.h"

int main(int argc, char* argv[]) {
    try {
        CommandLineArguments clArgs(argc, argv);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
