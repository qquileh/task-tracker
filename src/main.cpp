#include <iostream>
#include "../include/CLArgs.h"
#include "../include/CommandDispatcher.h"

int main(int argc, char* argv[]) {
    CommandLineInterface clInterface;
    CommandDispatcher dispatcher(clInterface);
    try {
        CommandLineArguments clArgs(argc, argv);
        auto command = clArgs.getCommand();
        dispatcher.ExecuteCommand(command);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
