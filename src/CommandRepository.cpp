#include <iostream>
#include "../include/CommandRepository.h"
#include "../include/CLArgs.h"
#include <pqxx/pqxx>
#include <vector>


CommandRepository::CommandRepository(pqxx::connection& conn) : _conn(conn) {}

void CommandRepository::addStudent(const CommandLineArguments& clArgs) {
	const auto& args = clArgs.getArguments();
	const std::string& firstName = args[0];
	const std::string& lastName = args[1];

	try {
		pqxx::work txn(_conn);

		txn.exec_params(
			"INSERT INTO students (first_name, last_name) "
			"VALUES ($1, $2)",
			firstName,
			lastName
		);

		txn.commit();
		std::cout << "Student '" << firstName << " " << lastName << "' added successfully."
				  << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to add student: " + std::string(e.what()));
	}
}

void CommandRepository::addTask(const CommandLineArguments& clArgs) {
	const auto& args = clArgs.getArguments();
	const std::string& title = args[0];
	std::vector<int> studentIds;

	for (size_t i = 1; i != args.size(); ++i) {
		try {
			int studentId = std::stoi(args[i]);
			studentIds.push_back(studentId);
		} catch (const std::invalid_argument&) {
			throw std::invalid_argument("Invalid student ID: " + args[i]);
		}
	}



	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec_params(
			"INSERT INTO tasks (title, status) "
			"VALUES ($1, 'not completed')",
			title
		);

		int taskId = result[0][0].as<int>();

		for (int studentId : studentIds) {
			txn.exec_params(
				"INSERT INTO student_tasks (student_id, task_id) "
				"VALUES ($1, $2)",
				studentId,
				taskId
			);
		}

		txn.commit();
		std::cout << "Task '" << title << "' added successfully with ID " << taskId
				  << " for students: ";
		for (int studentId : studentIds) {
			std::cout << studentId << " ";
		}
		std::cout << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to add student: " + std::string(e.what()));
	}
}

void CommandRepository::deleteStudent(const CommandLineArguments& clArgs) {
	const auto& args = clArgs.getArguments();
	if (args.empty()) {
		throw std::invalid_argument("DeleteStudent requires student ID!");
	}

	int studentId;
	try {
		studentId = std::stoi(args[0]);
	} catch (const std::invalid_argument&) {
		throw std::invalid_argument("Invalid student ID: " + args[0]);
	}

	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec_params(
			"DELETE FROM students " 
			"WHERE student_id = $1 "
			"RETURNING first_name, last_name",
			studentId
		);

		if (result.empty()) {
			throw std::runtime_error("Student with ID " + std::to_string(studentId) + " not found.");
		}

		std::string firstName = result[0][0].as<std::string>();
		std::string lastName = result[0][1].as<std::string>();

		txn.commit();
		std::cout << "Student '" << firstName << " " << lastName
			<< "' (ID: " << studentId << ") deleted successfully." << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to delete student: " + std::string(e.what()));
	}
}

void CommandRepository::deleteTask(const CommandLineArguments& clArgs) {
	const auto& args = clArgs.getArguments();
	if (args.empty()) {
		throw std::invalid_argument("DeleteTask requires task ID!");
	}

	int taskId;
	try {
		taskId = std::stoi(args[0]);
	} catch (const std::invalid_argument&) {
		throw std::invalid_argument("Invalid student ID: " + args[0]);
	}

	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec_params(
			"DELETE FROM tasks "
			"WHERE task_id = $1 "
			"RETURNING title",
			taskId
		);

		if (result.empty()) {
			throw std::runtime_error("Task with ID " + std::to_string(taskId) + " not found.");
		}

		std::string taskTitle = result[0][0].as<std::string>();

		txn.commit();
		std::cout << "Task '" << taskTitle << "' (ID: " << taskId << ") deleted successfully."
			      << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to delete task: " + std::string(e.what()));
	}
}

void CommandRepository::listDone(const CommandLineArguments& clArgs) {
	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec(
			"SELECT task_id, title, created_at, updated_at FROM tasks "
			"WHERE status = 'completed'"
		);

		if (result.empty()) {
			std::cout << "No completed tasks found." << std::endl;
			return;
		}

		std::cout << "Completed Tasks:" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "ID\tTitle\t\tCreated At\t\tUpdated At" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;

		for (const auto& row : result) {
			int taskId = row["task_id"].as<int>();
			std::string title = row["title"].as<std::string>();
			std::string createdAt = row["created_at"].as<std::string>();
			std::string updatedAt = row["updated_at"].as<std::string>();

			std::cout << taskId << "\t" << title << "\t" << createdAt << "\t" << updatedAt << std::endl;
		}

		std::cout << "-------------------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to list completed tasks: " + std::string(e.what()));
	}
}

void CommandRepository::listInProgress(const CommandLineArguments& clArgs) {
	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec(
			"SELECT task_id, title, created_at, updated_at FROM tasks "
			"WHERE status = 'in progress'"
		);

		if (result.empty()) {
			std::cout << "No tasks in progress found." << std::endl;
			return;
		}

		std::cout << "Tasks in progress:" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "ID\tTitle\t\tCreated At\t\tUpdated At" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;

		for (const auto& row : result) {
			int taskId = row["task_id"].as<int>();
			std::string title = row["title"].as<std::string>();
			std::string createdAt = row["created_at"].as<std::string>();
			std::string updatedAt = row["updated_at"].as<std::string>();

			std::cout << taskId << "\t" << title << "\t" << createdAt << "\t" << updatedAt << std::endl;
		}

		std::cout << "-------------------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to list tasks in progress: " + std::string(e.what()));
	}
}

void CommandRepository::listStudents(const CommandLineArguments& clArgs) {
	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec(
			"SELECT student_id, first_name, last_name FROM students"
		);

		if (result.empty()) {
			std::cout << "No students found." << std::endl;
			return;
		}

		std::cout << "Students:" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "ID\tFirst Name\tLast Name" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;

		for (const auto& row : result) {
			int studentId = row["id"].as<int>();
			std::string firstName = row["first_name"].as<std::string>();
			std::string lastName = row["last_name"].as<std::string>();

			std::cout << studentId << "\t" << firstName << "\t\t" << lastName << std::endl;
		}

		std::cout << "-------------------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to list students: " + std::string(e.what()));
	}
}

void CommandRepository::listTasks(const CommandLineArguments& clArgs) {
	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec(
			"SELECT task_id, title, created_at, updated_at FROM tasks"
		);

		if (result.empty()) {
			std::cout << "No tasks found." << std::endl;
			return;
		}

		std::cout << "Tasks:" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "ID\tTitle\t\tCreated At\t\tUpdated At" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;

		for (const auto& row : result) {
			int taskId = row["task_id"].as<int>();
			std::string title = row["title"].as<std::string>();
			std::string createdAt = row["created_at"].as<std::string>();
			std::string updatedAt = row["updated_at"].as<std::string>();

			std::cout << taskId << "\t" << title << "\t" << createdAt << "\t" << updatedAt << std::endl;
		}

		std::cout << "-------------------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to list tasks: " + std::string(e.what()));
	}
}

void CommandRepository::listToDo(const CommandLineArguments& clArgs) {
	try {
		pqxx::work txn(_conn);

		pqxx::result result = txn.exec(
			"SELECT task_id, title, created_at, updated_at FROM tasks "
			"WHERE status = 'not completed'"
		);

		if (result.empty()) {
			std::cout << "No tasks to do found." << std::endl;
			return;
		}

		std::cout << "Tasks to do:" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;
		std::cout << "ID\tTitle\t\tCreated At\t\tUpdated At" << std::endl;
		std::cout << "-------------------------------------------------------------" << std::endl;

		for (const auto& row : result) {
			int taskId = row["task_id"].as<int>();
			std::string title = row["title"].as<std::string>();
			std::string createdAt = row["created_at"].as<std::string>();
			std::string updatedAt = row["updated_at"].as<std::string>();

			std::cout << taskId << "\t" << title << "\t" << createdAt << "\t" << updatedAt << std::endl;
		}

		std::cout << "-------------------------------------------------------------" << std::endl;
	} catch (const std::exception& e) {
		throw std::runtime_error("Failed to list tasks to do: " + std::string(e.what()));
	}
}

void CommandRepository::markDone(const CommandLineArguments& clArgs) {
	std::cout << "markDone()" << std::endl;
}

void CommandRepository::markInProgress(const CommandLineArguments& clArgs) {
	std::cout << "markInProgress()" << std::endl;
}

void CommandRepository::updateTask(const CommandLineArguments& clArgs) {
	std::cout << "updateTask()" << std::endl;
}
