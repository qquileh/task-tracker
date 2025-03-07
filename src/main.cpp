#include <iostream>
#include "../include/CLArgs.h"
#include "../include/CommandDispatcher.h"

int main(int argc, char* argv[]) {
    TaskRepository taskRepository;
    CommandDispatcher dispatcher(taskRepository);
    try {
        CommandLineArguments clArgs(argc, argv);
        dispatcher.ExecuteCommand(clArgs);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
