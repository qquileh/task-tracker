#include "../include/CommandDispatcher.h"


CommandDispatcher::CommandDispatcher(CommandLineInterface& cli) {
    _dispatcher[CommandLineArguments::Command::Add] = [&cli]() { cli.addTask(); };
    _dispatcher[CommandLineArguments::Command::Update] = [&cli]() { cli.updateTask(); };
    _dispatcher[CommandLineArguments::Command::Delete] = [&cli]() { cli.deleteTask(); };
    _dispatcher[CommandLineArguments::Command::MarkInProgress] = [&cli]() { cli.markInProgress(); };
    _dispatcher[CommandLineArguments::Command::MarkDone] = [&cli]() { cli.markDone(); };
    _dispatcher[CommandLineArguments::Command::List] = [&cli]() { cli.list(); };
    _dispatcher[CommandLineArguments::Command::ListDone] = [&cli]() { cli.listDone(); };
    _dispatcher[CommandLineArguments::Command::ListTodo] = [&cli]() { cli.listTodo(); };
    _dispatcher[CommandLineArguments::Command::ListInProgress] = [&cli]() { cli.listInProgress(); };
}

void CommandDispatcher::ExecuteCommand(const CommandLineArguments::Command& cmd) const {
    auto it = _dispatcher.find(cmd);
    if (it != _dispatcher.end()) {
        it->second();
    } else {
        throw std::invalid_argument("Unknown command");
    }
}