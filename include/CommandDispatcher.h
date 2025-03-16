#pragma once

#include <functional>
#include <string>
#include <unordered_map>

#include "./CLArgs.h"
#include "./TaskRepository.h"


class CommandDispatcher {
private:
    std::unordered_map<CommandLineArguments::Command, std::function<std::string(const CommandLineArguments&)>> _dispatcher;

public:
    CommandDispatcher(TaskRepository& taskRepository);
    std::string generateQuery(const CommandLineArguments& clArguments) const;
};
