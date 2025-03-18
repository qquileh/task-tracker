#pragma once

#include <functional>
#include <string>
#include <unordered_map>

#include "./CLArgs.h"
#include "./TaskRepository.h"


class CommandDispatcher {
private:
    std::unordered_map<CommandLineArguments::Command, std::function<void(const CommandLineArguments&)>> _dispatcher;

public:
    CommandDispatcher(TaskRepository& taskRepository);
    void executeCommand(const CommandLineArguments& clArguments) const;
};
