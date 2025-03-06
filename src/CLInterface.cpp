#include <iostream>
#include "../include/CLInterface.h"


void CommandLineInterface::addTask() {
	std::cout << "addTask()" << std::endl;
}

void CommandLineInterface::updateTask() {
	std::cout << "updateTask()" << std::endl;
}

void CommandLineInterface::deleteTask() {
	std::cout << "deleteTask()" << std::endl;
}

void CommandLineInterface::markInProgress() {
	std::cout << "markInProgress()" << std::endl;
}

void CommandLineInterface::markDone() {
	std::cout << "markDone()" << std::endl;
}

void CommandLineInterface::list() {
	std::cout << "list()" << std::endl;
}

void CommandLineInterface::listDone() {
	std::cout << "listDone()" << std::endl;
}

void CommandLineInterface::listTodo() {
	std::cout << "listTodo()" << std::endl;
}

void CommandLineInterface::listInProgress() {
	std::cout << "listInProgress()" << std::endl;
}
