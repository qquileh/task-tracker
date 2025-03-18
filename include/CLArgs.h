#pragma once

#include <string>
#include <vector>
#include <stdexcept>


class CommandLineArguments {
public:
    enum class Command {
        AddStudent,
        AddTask,
        UpdateTask,
        DeleteTask,
        DeleteStudent,
        MarkInProgress,
        MarkDone,
        ListTasks,
        ListStudents,
        ListDone,
        ListInProgress,
        ListToDo,
        Unknown
    };

    CommandLineArguments(int argc, char* argv[]);
    const Command& getCommand() const;
    const std::vector<std::string>& getArguments() const;

private:
    Command _command;
    std::vector<std::string> _arguments;
    size_t _argStartNum = 1;

    void parseAddSubcommand(const std::string& subcmd);
    void parseDeleteSubcommand(const std::string& subcmd);
    void parseListSubcommand(const std::string& subcmd);
    void parseArguments(int argc, char* argv[], size_t start);
};
