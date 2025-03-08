#include "../include/CLArgs.h"


CommandLineArguments::Command CommandLineArguments::getCommand() const {
    return _command;
}

void CommandLineArguments::parseCommand(const std::string& cmd) {
    if (cmd == "add") {
        _command = Command::Add;
    } else if (cmd == "update") {
        _command = Command::Update;
    } else if (cmd == "delete") {
        _command = Command::Delete;
    } else if (cmd == "mark-in-progress") {
        _command = Command::MarkInProgress;
    } else if (cmd == "mark-done") {
        _command = Command::MarkDone;
    } else if (cmd == "list") {
        _command = Command::List;
    } else {
        throw std::invalid_argument("Invalid command: " + cmd);
    }
}

void CommandLineArguments::parseListSubcommand(const std::string& subcmd) {
    if (subcmd == "done") {
        _command = Command::ListDone;
    } else if (subcmd == "todo") {
        _command = Command::ListTodo;
    } else if (subcmd == "in-progress") {
        _command = Command::ListInProgress;
    }
}

void CommandLineArguments::parseArguments(int argc, char* argv[], size_t start) {
    for (size_t i = start; i < argc; ++i) {
        _arguments.push_back(argv[i]);
    }
}

CommandLineArguments::CommandLineArguments(int argc, char* argv[]) {
    if (argc > 1) {
        parseCommand(argv[1]);
        if (_command == Command::List && argc > 2) {
            parseListSubcommand(argv[2]);
            _argStartNum = 3;
        }
        parseArguments(argc, argv, _argStartNum);
    } else {
        throw std::invalid_argument("No command provided!");
    }
}
