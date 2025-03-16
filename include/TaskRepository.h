#pragma once

#include <vector>
#include <string>
#include "./task.h"
#include "./CLArgs.h"


class TaskRepository {
public:
    std::string addStudent(const CommandLineArguments& clArgs);
    std::string addTask(const CommandLineArguments& clArgs);
    std::string deleteStudent(const CommandLineArguments& clArgs);
    std::string deleteTask(const CommandLineArguments& clArgs);
    std::string listDone(const CommandLineArguments& clArgs);
    std::string listInProgress(const CommandLineArguments& clArgs);
    std::string listStudents(const CommandLineArguments& clArgs);
    std::string listTasks(const CommandLineArguments& clArgs);
    std::string listToDo(const CommandLineArguments& clArgs);
    std::string markDone(const CommandLineArguments& clArgs);
    std::string markInProgress(const CommandLineArguments& clArgs);
    std::string updateTask(const CommandLineArguments& clArgs);
};
