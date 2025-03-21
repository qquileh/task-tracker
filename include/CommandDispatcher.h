#pragma once

#include <functional>
#include <string>
#include <unordered_map>
#include "./CommandLineArguments.h"
#include "./CommandRepository.h"


class CommandDispatcher {
private:
    std::unordered_map<CommandLineArguments::Command, std::function<void(const CommandLineArguments&)>> _dispatcher;

public:
    CommandDispatcher(CommandRepository& taskRepository);
    void executeCommand(const CommandLineArguments& clArgs) const;
};
