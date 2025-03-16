#include <iostream>
#include "../include/CLArgs.h"
#include "../include/CommandDispatcher.h"
#include "../include/TaskRepository.h"
#include "../include/DatabaseConnectionConfig.h"
#include <pqxx/pqxx>


int main(int argc, char* argv[]) {
    TaskRepository taskRepository;
    CommandDispatcher dispatcher(taskRepository);
    DatabaseConnectionConfig config;

    try {
        pqxx::connection conn(config.getConnectionString());
        CommandLineArguments clArgs(argc, argv);
        std::string query = dispatcher.generateQuery(clArgs);
        conn.close();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
