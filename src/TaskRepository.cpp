#include <iostream>
#include "../include/TaskRepository.h"
#include "../include/CLArgs.h"


void TaskRepository::addTask(const CommandLineArguments& clArgs) {
	std::cout << "addTask()" << std::endl;
}

void TaskRepository::updateTask(const CommandLineArguments& clArgs) {
	std::cout << "updateTask()" << std::endl;
}

void TaskRepository::deleteTask(const CommandLineArguments& clArgs) {
	std::cout << "deleteTask()" << std::endl;
}

void TaskRepository::markInProgress(const CommandLineArguments& clArgs) {
	std::cout << "markInProgress()" << std::endl;
}

void TaskRepository::markDone(const CommandLineArguments& clArgs) {
	std::cout << "markDone()" << std::endl;
}

void TaskRepository::list(const CommandLineArguments& clArgs) {
	std::cout << "list()" << std::endl;
}

void TaskRepository::listDone(const CommandLineArguments& clArgs) {
	std::cout << "listDone()" << std::endl;
}

void TaskRepository::listTodo(const CommandLineArguments& clArgs) {
	std::cout << "listTodo()" << std::endl;
}

void TaskRepository::listInProgress(const CommandLineArguments& clArgs) {
	std::cout << "listInProgress()" << std::endl;
}
