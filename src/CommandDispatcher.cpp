#include "../include/CommandDispatcher.h"


CommandDispatcher::CommandDispatcher(TaskRepository& taskRepository) {
    _dispatcher[CommandLineArguments::Command::AddStudent] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.addStudent(clArgs); };
    _dispatcher[CommandLineArguments::Command::AddTask] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.addTask(clArgs); };
    _dispatcher[CommandLineArguments::Command::DeleteStudent] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.deleteStudent(clArgs); };
    _dispatcher[CommandLineArguments::Command::DeleteTask] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.deleteTask(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListDone] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.listDone(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListInProgress] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.listInProgress(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListStudents] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.listStudents(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListTasks] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.listTasks(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListToDo] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.listToDo(clArgs); };
    _dispatcher[CommandLineArguments::Command::MarkDone] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.markDone(clArgs); };
    _dispatcher[CommandLineArguments::Command::MarkInProgress] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.markInProgress(clArgs); };
    _dispatcher[CommandLineArguments::Command::UpdateTask] = [&taskRepository](const CommandLineArguments& clArgs) { return taskRepository.updateTask(clArgs); };
}

std::string CommandDispatcher::generateQuery(const CommandLineArguments& clArguments) const {
    auto it = _dispatcher.find(clArguments.getCommand());
    std::string result;
    if (it != _dispatcher.end()) {
        result = it->second(clArguments);
    } else {
        throw std::invalid_argument("Unknown command");
    }
    return result;
}
