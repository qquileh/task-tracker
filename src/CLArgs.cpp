#include "../include/CLArgs.h"

CommandLineArguments::Command CommandLineArguments::getCommand() const {
    return _command;
}

const std::vector<std::string>& CommandLineArguments::getArguments() const {
    return _arguments;
}

void CommandLineArguments::parseAddSubcommand(const std::string& subcmd) {
    if (subcmd == "student") {
        _command = Command::AddStudent;
    } else if (subcmd == "task") {
        _command = Command::AddTask;
    } else {
        throw std::invalid_argument("Invalid add subcommand: " + subcmd);
    }
}

void CommandLineArguments::parseDeleteSubcommand(const std::string& subcmd) {
    if (subcmd == "task") {
        _command = Command::DeleteTask;
    } else if (subcmd == "student") {
        _command = Command::DeleteStudent;
    } else {
        throw std::invalid_argument("Invalid delete subcommand: " + subcmd);
    }
}

void CommandLineArguments::parseListSubcommand(const std::string& subcmd) {
    if (subcmd == "tasks") {
        _command = Command::ListTasks;
    } else if (subcmd == "students") {
        _command = Command::ListStudents;
    } else if (subcmd == "done") {
        _command = Command::ListDone;
    } else if (subcmd == "in-progress") {
        _command = Command::ListInProgress;
    } else if (subcmd == "to-do") {
        _command = Command::ListToDo;
    } else {
        throw std::invalid_argument("Invalid list subcommand: " + subcmd);
    }
}

void CommandLineArguments::parseArguments(int argc, char* argv[], size_t start) {
    for (size_t i = start; i < argc; ++i) {
        _arguments.push_back(argv[i]);
    }
}

CommandLineArguments::CommandLineArguments(int argc, char* argv[]) {
    if (argc < 2) throw std::invalid_argument("No command provided!");

    std::string mainCmd = argv[1];
    _argStartNum = 2;

    if (mainCmd == "add") {
        if (argc < 3) {
            throw std::invalid_argument("Add command requires subcommand!");
        }
        parseAddSubcommand(argv[2]);
        _argStartNum = 3;
    } else if (mainCmd == "delete") {
        if (argc < 3) {
            throw std::invalid_argument("Delete command requires subcommand!");
        }
        parseDeleteSubcommand(argv[2]);
        _argStartNum = 3;
    } else if (mainCmd == "mark-in-progress") {
        _command = Command::MarkInProgress;
    } else if (mainCmd == "mark-done") {
        _command = Command::MarkDone;
    } else if (mainCmd == "list") {
        if (argc < 3) {
            throw std::invalid_argument("List command requires subcommand!");
        }
        parseListSubcommand(argv[2]);
        _argStartNum = 3;
    } else {
        throw std::invalid_argument("Unknown command: " + mainCmd);
    }

    parseArguments(argc, argv, _argStartNum);

    switch (_command) {
        case Command::AddStudent:
            if (_arguments.size() < 2) {
                throw std::invalid_argument("AddStudent requires first_name and last_name!");
            }
            break;
        case Command::AddTask:
            if (_arguments.size() < 2) {
                throw std::invalid_argument("AddTask requires title and at least one student_id!");
            }
            break;
        case Command::DeleteStudent:
        case Command::DeleteTask:
        case Command::MarkInProgress:
        case Command::MarkDone:
            if (_arguments.empty()) {
                throw std::invalid_argument("Command requires ID!");
            }
            break;
        default:
            break;
    }
}
