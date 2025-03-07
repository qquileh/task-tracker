#pragma once

#include <vector>
#include <string>
#include "./task.h"


class TaskRepository {
private:
	std::vector<Task> _tasks;

public:
	TaskRepository() = default;
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
