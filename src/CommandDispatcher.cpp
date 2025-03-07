#include "../include/CommandDispatcher.h"


CommandDispatcher::CommandDispatcher(TaskRepository& taskRepository) {
    _dispatcher[CommandLineArguments::Command::Add] = [&taskRepository]() { taskRepository.addTask(); };
    _dispatcher[CommandLineArguments::Command::Update] = [&taskRepository]() { taskRepository.updateTask(); };
    _dispatcher[CommandLineArguments::Command::Delete] = [&taskRepository]() { taskRepository.deleteTask(); };
    _dispatcher[CommandLineArguments::Command::MarkInProgress] = [&taskRepository]() { taskRepository.markInProgress(); };
    _dispatcher[CommandLineArguments::Command::MarkDone] = [&taskRepository]() { taskRepository.markDone(); };
    _dispatcher[CommandLineArguments::Command::List] = [&taskRepository]() { taskRepository.list(); };
    _dispatcher[CommandLineArguments::Command::ListDone] = [&taskRepository]() { taskRepository.listDone(); };
    _dispatcher[CommandLineArguments::Command::ListTodo] = [&taskRepository]() { taskRepository.listTodo(); };
    _dispatcher[CommandLineArguments::Command::ListInProgress] = [&taskRepository]() { taskRepository.listInProgress(); };
}

void CommandDispatcher::ExecuteCommand(const CommandLineArguments& clArguments) const {
    auto it = _dispatcher.find(clArguments.getCommand());
    if (it != _dispatcher.end()) {
        it->second();
    } else {
        throw std::invalid_argument("Unknown command");
    }
}