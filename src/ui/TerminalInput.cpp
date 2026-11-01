#include "ui/TerminalInterface.h"

#include <iostream>
#include <stdexcept>
#include <string>

#include "ErrorHandler.h"

namespace Familiar {
    int TerminalInterface::readMenuChoice() {
        while (true) {
            showMenu();
    
            int choice = readNumber();
    
            if (choice == -1) {
                continue;
            }
    
            if (isValidMenuChoice(choice)) {
                return choice;
            }
    
            std::cout << "Invalid choice. Please select a number from 1 to .\n\n";
        }
    }

    int TerminalInterface::readNumber() {
        std::string input;
    
        if (!std::getline(std::cin, input)) {
            if (std::cin.eof()) {
                throw std::runtime_error(
                    "EOF: TerminalInterface::readNumber CIN_EOF_ERROR\n");
            }
    
            std::cin.clear();
            return -1;
        }
    
        try {
            std::size_t pos = 0;
            int number = std::stoi(input, &pos);
    
            // Reject inputs such as "1abc" or "2.5".
            if (pos != input.size()) {
                Familiar::reportError("Invalid input. Please enter a number.");
                return -1;
            }
    
            return number;
        } catch (const std::invalid_argument &) {
            Familiar::reportError("Invalid input. Please enter a number.");
            return -1;
        } catch (const std::out_of_range &) {
            Familiar::reportError("Number is out of range.");
            return -1;
        }
    }
    
    void TerminalInterface::readWord(std::string &output) {
        if (!std::getline(std::cin, output)) {
            if (std::cin.eof()) {
                throw std::runtime_error(
                    "EOF: TerminalInterface::readWord CIN_EOF_ERROR\n");
            }
    
            std::cin.clear();
            output.clear();
        }
    }
    
    
} // namespace Familiar