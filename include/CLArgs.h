#pragma once

#include <string>
#include <vector>

class CommandLineArguments {
public:
	std::string command;
	std::vector<std::string> arguments;

	CommandLineArguments(int argc, char* argv[]);
};