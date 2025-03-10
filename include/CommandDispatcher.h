#pragma once

#include <functional>
#include <unordered_map>

#include "./CLArgs.h"
#include "./TaskRepository.h"


class CommandDispatcher {
private:
	std::unordered_map<CommandLineArguments::Command, std::function<void()>> _dispatcher;

public:
	CommandDispatcher(TaskRepository& taskRepository);
	void ExecuteCommand(const CommandLineArguments& clArguments) const;
};