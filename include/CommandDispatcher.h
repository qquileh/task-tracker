#pragma once

#include <functional>
#include <unordered_map>

#include "./CLArgs.h"
#include "./CLInterface.h"


class CommandDispatcher {
private:
	std::unordered_map<CommandLineArguments::Command, std::function<void()>> _dispatcher;

public:
	CommandDispatcher(CommandLineInterface& cli);
	void ExecuteCommand(const CommandLineArguments::Command& cmd) const;
};