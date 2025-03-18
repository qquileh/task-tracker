#include <iostream>
#include "../include/CLArgs.h"
#include "../include/CommandDispatcher.h"
#include "../include/CommandRepository.h"
#include "../include/DatabaseConnectionConfig.h"
#include <pqxx/pqxx>


int main(int argc, char* argv[]) {
    DatabaseConnectionConfig config;

    try {
        pqxx::connection conn(config.getConnectionString());

        CommandRepository commandRepository(conn);
        CommandDispatcher dispatcher(commandRepository);

        CommandLineArguments clArgs(argc, argv);
        dispatcher.executeCommand(clArgs);

        conn.close();
    } catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument error: " << e.what() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Unexpected error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
