#pragma once

#include <vector>
#include <string>
#include "./task.h"


class CommandLineInterface {
private:
	std::vector<Task> tasks;

public:
	CommandLineInterface() = default;
	void addTask();
	void updateTask();
	void deleteTask();
	void markInProgress();
	void markDone();
	void list();
	void listDone();
	void listTodo();
	void listInProgress();
};