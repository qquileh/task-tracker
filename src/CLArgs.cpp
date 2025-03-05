#include "../include/CLArgs.h"

CommandLineArguments::CommandLineArguments(int argc, char* argv[]) {
	if (argc > 1) {
		this->command = argv[1];
		for (size_t i = 2; i != argc; ++i) {
			this->arguments.push_back(argv[i]);
		}
	}
}