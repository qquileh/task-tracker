#include "../include/CommandDispatcher.h"


CommandDispatcher::CommandDispatcher(TaskRepository& taskRepository) {
    _dispatcher[CommandLineArguments::Command::Add] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.addTask(clArgs); };
    _dispatcher[CommandLineArguments::Command::Update] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.updateTask(clArgs); };
    _dispatcher[CommandLineArguments::Command::Delete] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.deleteTask(clArgs); };
    _dispatcher[CommandLineArguments::Command::MarkInProgress] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.markInProgress(clArgs); };
    _dispatcher[CommandLineArguments::Command::MarkDone] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.markDone(clArgs); };
    _dispatcher[CommandLineArguments::Command::List] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.list(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListDone] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listDone(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListTodo] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listTodo(clArgs); };
    _dispatcher[CommandLineArguments::Command::ListInProgress] = [&taskRepository](const CommandLineArguments& clArgs) { taskRepository.listInProgress(clArgs); };
}

void CommandDispatcher::ExecuteCommand(const CommandLineArguments& clArguments) const {
    auto it = _dispatcher.find(clArguments.getCommand());
    if (it != _dispatcher.end()) {
        it->second(clArguments);
    } else {
        throw std::invalid_argument("Unknown command");
    }
}