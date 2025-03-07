#include <iostream>
#include "../include/TaskRepository.h"


void TaskRepository::addTask() {
	std::cout << "addTask()" << std::endl;
}

void TaskRepository::updateTask() {
	std::cout << "updateTask()" << std::endl;
}

void TaskRepository::deleteTask() {
	std::cout << "deleteTask()" << std::endl;
}

void TaskRepository::markInProgress() {
	std::cout << "markInProgress()" << std::endl;
}

void TaskRepository::markDone() {
	std::cout << "markDone()" << std::endl;
}

void TaskRepository::list() {
	std::cout << "list()" << std::endl;
}

void TaskRepository::listDone() {
	std::cout << "listDone()" << std::endl;
}

void TaskRepository::listTodo() {
	std::cout << "listTodo()" << std::endl;
}

void TaskRepository::listInProgress() {
	std::cout << "listInProgress()" << std::endl;
}
