#include <iostream>
#include "../include/TaskRepository.h"
#include "../include/CLArgs.h"


TaskRepository::TaskRepository(pqxx::connection& conn) : _conn(conn) {}

void TaskRepository::addStudent(const CommandLineArguments& clArgs) {
	std::cout << "addStudent()" << std::endl;
}

void TaskRepository::addTask(const CommandLineArguments& clArgs) {
	std::cout << "addTask()" << std::endl;
}

void TaskRepository::deleteStudent(const CommandLineArguments& clArgs) {
	std::cout << "deleteStudent()" << std::endl;
}

void TaskRepository::deleteTask(const CommandLineArguments& clArgs) {
	std::cout << "deleteTask()" << std::endl;
}

void TaskRepository::listDone(const CommandLineArguments& clArgs) {
	std::cout << "listDone()" << std::endl;
}

void TaskRepository::listInProgress(const CommandLineArguments& clArgs) {
	std::cout << "listInProgress()" << std::endl;
}

void TaskRepository::listStudents(const CommandLineArguments& clArgs) {
	std::cout << "listStudents()" << std::endl;
}

void TaskRepository::listTasks(const CommandLineArguments& clArgs) {
	std::cout << "listTasks()" << std::endl;
}

void TaskRepository::listToDo(const CommandLineArguments& clArgs) {
	std::cout << "listToDo()" << std::endl;
}

void TaskRepository::markDone(const CommandLineArguments& clArgs) {
	std::cout << "markDone()" << std::endl;
}

void TaskRepository::markInProgress(const CommandLineArguments& clArgs) {
	std::cout << "markInProgress()" << std::endl;
}

void TaskRepository::updateTask(const CommandLineArguments& clArgs) {
	std::cout << "updateTask()" << std::endl;
}
