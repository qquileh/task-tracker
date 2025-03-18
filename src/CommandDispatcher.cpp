#include "../include/CommandDispatcher.h"


CommandDispatcher::CommandDispatcher(TaskRepository& taskRepository) {
    _dispatcher[CommandLineArguments::Command::AddStudent] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.addStudent(clArgs); };
    _dispatcher[CommandLineArguments::Command::AddTask] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.addTask(clArgs); };
    _dispatcher[CommandLineArguments::Command::DeleteStudent] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.deleteStudent(clArgs); };
    _dispatcher[CommandLineArguments::Command::DeleteTask] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.deleteTask(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListDone] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listDone(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListInProgress] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listInProgress(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListStudents] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listStudents(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListTasks] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listTasks(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListToDo] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listToDo(clArgs); };
    _dispatcher[CommandLineArguments::Command::MarkDone] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.markDone(clArgs); };
    _dispatcher[CommandLineArguments::Command::MarkInProgress] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.markInProgress(clArgs); };
    _dispatcher[CommandLineArguments::Command::UpdateTask] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.updateTask(clArgs); };
}

void CommandDispatcher::executeCommand(const CommandLineArguments& clArguments) const {
    auto it = _dispatcher.find(clArguments.getCommand());
    if (it != _dispatcher.end()) {
        it->second(clArguments);
    } else {
        throw std::invalid_argument("Unknown command!");
    }
}
