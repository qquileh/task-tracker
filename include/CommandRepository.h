#pragma once

#include <vector>
#include <string>
#include "./CLArgs.h"
#include "pqxx/pqxx"


class CommandRepository {
private:
	pqxx::connection& _conn;

public:
	CommandRepository(pqxx::connection& conn);

	void addStudent(const CommandLineArguments& clArgs);
	void addTask(const CommandLineArguments& clArgs);
	void deleteStudent(const CommandLineArguments& clArgs);
	void deleteTask(const CommandLineArguments& clArgs);
	void listDone(const CommandLineArguments& clArgs);
	void listInProgress(const CommandLineArguments& clArgs);
	void listStudents(const CommandLineArguments& clArgs);
	void listTasks(const CommandLineArguments& clArgs);
	void listToDo(const CommandLineArguments& clArgs);
	void markDone(const CommandLineArguments& clArgs);
	void markInProgress(const CommandLineArguments& clArgs);
	void updateTask(const CommandLineArguments& clArgs);
};
