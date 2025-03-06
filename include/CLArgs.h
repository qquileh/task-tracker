#pragma once

#include <string>
#include <vector>
#include <stdexcept>


class CommandLineArguments {
public:
    enum class Command {
        Add,
        Update,
        Delete,
        MarkInProgress,
        MarkDone,
        List,
        ListDone,
        ListTodo,
        ListInProgress,
        Unknown
    };

	CommandLineArguments(int argc, char* argv[]);

private:
    Command _command;
    std::vector<std::string> _arguments;
    size_t _argStartNum = 2;

    void parseCommand(const std::string& cmd);
    void parseListSubcommand(const std::string& subcmd);
    void parseArguments(int argc, char* argv[], size_t start);
};