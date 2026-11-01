#include "ui/TerminalInterface.h"

#include <iostream>
#include <vector>

namespace Familiar {

    void TerminalInterface::showTitle() const {
        std::cout << "================================\n";
        std::cout << "           FAMILIAR\n";
        std::cout << "================================\n\n";
        std::cout << "Welcome to Familiar.\n\n";
    }

    void TerminalInterface::showMenu() const {
        std::cout << "1. Create a Project\n";
        std::cout << "2. Select a project\n";
        std::cout << "3. List Projects\n";
        std::cout << "4. Add Task to Project\n";
        std::cout << "5. Exit\n\n";
        std::cout << "Select an option: ";
    }

    void TerminalInterface::printProject(const Project &p) {
        std::cout << p.getName() << "\n";
        std::cout << p.getDescription() << "\n";
        std::cout << "Status: " << p.getStatus() << "\n";
    }

    void TerminalInterface::printTasks(const std::vector<Task> &t) {
        std::cout << "[ Tasks ]\n";

        if (t.empty()) {
            std::cout << "No tasks available.\n";
            return;
        }

        for (std::size_t i = 0; i < t.size(); ++i) {
            std::cout << i + 1 << " - " << t[i].getTitle() << "\n";
            std::cout << t[i].getDescription() << "\n";
        }
    }

    void TerminalInterface::printReport() const {
        if (selectedProject == nullptr) {
            std::cout << "No project selected.\n\n";
            return;
        }

        std::cout << "=== SELECTED PROJECT ===\n";
        std::cout << selectedProject->getName() << '\n';
        std::cout << selectedProject->getDescription() << '\n';
        std::cout << "Status: " << selectedProject->getStatus() << '\n';

        std::cout << "\n[ Tasks ]\n";

        const auto tasks = selectedProject->getTasks();

        if (tasks.empty()) {
            std::cout << "No tasks available.\n";
        } else {
            for (std::size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << " - " << tasks[i].getTitle() << '\n';
                std::cout << tasks[i].getDescription() << '\n';
            }
        }
        std::cout << '\n';
    }

}