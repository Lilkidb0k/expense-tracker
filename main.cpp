#include <iostream>
#include <string>
#include <cstdlib>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";
const std::string RESET = "\033[0m";

int main() {
    std::cout << BOLD << "\n\n==== Expense Tracker ====\n\n" << RESET;
    std::cout << BOLD << "1. " << RESET << "Add Expense\n";
    std::cout << BOLD << "2. " << RESET << "Remove Expense\n";
    std::cout << BOLD << "3. " << RESET << "View All Expenses\n";
    std::cout << BOLD << "4. " << RESET << "Show Total Spent\n";
    std::cout << BOLD << "5. " << RESET << "Show Spending by Category\n";
    std::cout << BOLD << "6. " << RESET << "Exit\n";

    std::cin.ignore();
    std::cin.get();
}