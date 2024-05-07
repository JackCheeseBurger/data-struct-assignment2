#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "s_linked.h"
#include "s_linked.cpp"


int argument;

using ListType = single_linked<int>;
ListType list;

// Get Input/Waiting
int getIntInput() {
    int input;
    while (!(std::cin >> input)) {
        // Clear the error flag
        std::cin.clear();
        // Ignore the rest of the input line
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input. Please enter an integer: ";
    }
    return input;
}

bool getIntInputwQuit() {
    std::string input;
    std::cin >> input;
    if (input == "q" || input == "Q") {
        std::cout << "Quitting... (Press Enter to continue)\n";
        while (std::cin.get() != '\n'); // Read and discard characters until newline is encountered
        return false;
    }
    if (!isdigit(input[0])) {
        std::cout << "Invalid input. Please enter an integer or 'q' to quit.\n";
        return getIntInputwQuit();
    }
    argument = std::stoi(input);
    return true;
}

bool waitForQ() {
    std::cout << "Enter 'q' to quit: ";
    char input;
    while (std::cin >> input) {
        if (input == 'q' || input == 'Q') {
            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return true; // Return true if 'q' or 'Q' is entered
        }
        std::cout << "Enter 'q' to quit: ";
    }
    return false; // If there's an error with input or EOF, return false
}

// Menu Function:

bool mainMenu() {
    std::system("cls || clear");
    argument = 0;
    std::cout << "-------------------------------\n" << std::setw(5) << "" << "Main Menu" << "\n-------------------------------\n";
    std::cout << std::setw(2) << "" << "1:Push Front, 2:Pop Front, 3:Push Back, 4:Pop Back, 5:Front, "
        << "6:Back, 7:Empty, 8:Insert, 9:Remove, 10:Find.\n" << std::setw(2) << "" << "or Enter 'q' to quit: ";
    while (getIntInputwQuit()) {
        switch (argument) {
        case 1:
            // Push Front
            std::system("cls || clear");
            std::cout << "Executing Push Front:\n";
            std::cout << "Old Front: " << list.front() << "\n";
            std::cout << "Enter input: ";
            list.push_front(getIntInput());
            std::cout << "New Back: " << list.front() << "\n";
            waitForQ();
            break;
        case 2:
            // Pop Front
            std::system("cls || clear");
            std::cout << "Executing Pop Front:\n";
            std::cout << "Old Front: " << list.front() << "\n";
            list.pop_front();
            std::cout << "New Front: " << list.front() << "\n";
            waitForQ();
            break;
        case 3:
            // Push Back
            std::system("cls || clear");
            std::cout << "Executing Push Back:\n";
            std::cout << "Old Back: " << list.back() << "\n";
            std::cout << "Enter input: ";
            list.push_back(getIntInput());
            std::cout << "New Back: " << list.back() << "\n";
            waitForQ();
            break;
        case 4:
            // Pop Back
            std::system("cls || clear");
            std::cout << "Executing Pop Back:\n";
            std::cout << "Old Back: " << list.back() << "\n";
            list.pop_back();
            std::cout << "New Back: " << list.back() << "\n";
            waitForQ();
            break;
        case 5:
            // Front
            std::system("cls || clear");
            std::cout << "Executing Front: ";
            std::cout << list.front() << "\n";
            waitForQ();
            break;
        case 6:
            // Back
            std::system("cls || clear");
            std::cout << "Executing Back: ";
            std::cout << list.back() << "\n";
            waitForQ();
            break;
        case 7:
            // Empty
            std::system("cls || clear");
            std::cout << "Executing Empty: ";
            if (list.empty()) {
                std::cout << "List is Empty\n";
            }
            else {
                std::cout << "List is not Empty\n";
            }
            waitForQ();
            break;
        case 8:
            // Insert
            std::system("cls || clear");
            std::cout << "Executing Insert:\n";
            std::cout << "Enter Index then Enter New Value:\n";
            list.insert(getIntInput(),getIntInput());
            waitForQ();
            break;
        case 9:
            // Remove
            std::system("cls || clear");
            std::cout << "Executing Remove:\n";
            std::cout << "Enter Index: ";
            list.remove(getIntInput());
            waitForQ();
            break;
        case 10:
            // Find
            std::system("cls || clear");
            std::cout << "Executing Find:\n";
            std::cout << "Enter Target: ";
            std::cout << "Target Found at Index: " << list.find(getIntInput()) << "\n";
            waitForQ();
            break;
        default:
            break;
        }
        std::system("cls || clear");
        argument = 0;
        std::cout << "-------------------------------\n" << std::setw(5) << "" << "Main Menu" << "\n-------------------------------\n";
        std::cout << std::setw(2) << "" << "1:Push Front, 2:Pop Front, 3:Push Back, 4:Pop Back, 5:Front, "
            << "6:Back, 7:Empty, 8:Insert, 9:Remove, 10:Find.\n" << std::setw(2) << "" << "or Enter 'q' to quit: ";
    }
    return true;
}

int main() {
    list.push_back(30);
    list.push_back(15);
    list.push_back(4);
    list.push_back(20);
    list.push_back(18);
    list.push_back(19);
    list.push_back(35);
    list.push_back(32);
    list.push_back(38);
    mainMenu();

	return EXIT_SUCCESS;
}