#pragma once

#include <vector>
#include <string>
#include "./task.h"
#include "./CLArgs.h"


class TaskRepository {
private:
    std::vector<Task> _tasks;

public:
    TaskRepository() = default;
    void addTask(const CommandLineArguments& clArgs);
    void updateTask(const CommandLineArguments& clArgs);
    void deleteTask(const CommandLineArguments& clArgs);
    void markInProgress(const CommandLineArguments& clArgs);
    void markDone(const CommandLineArguments& clArgs);
    void list(const CommandLineArguments& clArgs);
    void listDone(const CommandLineArguments& clArgs);
    void listTodo(const CommandLineArguments& clArgs);
    void listInProgress(const CommandLineArguments& clArgs);
};
