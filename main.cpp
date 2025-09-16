#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <map>
#include <limits>

const std::string RED = "\033[31m";
const std::string GREEN = "\033[32m";
const std::string YELLOW = "\033[33m";
const std::string BLUE = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN = "\033[36m";
const std::string BOLD = "\033[1m";
const std::string RESET = "\033[0m";

struct Expense {
    std::string category;
    double amount;
};

void pause() {
    std::cout << YELLOW << "\nPress ENTER to continue..." << RESET;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cin.get();
}

void addExpense(std::vector<Expense>& expenses) {
    Expense e;
    std::cout << "Enter category: ";
    std::cin >> e.category; 
    std::cout << "Enter amount: ";
    std::cin >> e.amount;

    expenses.push_back(e);
    std::cout << GREEN << "Expense added successfully!\n" << RESET;
}
void removeExpense(std::vector<Expense>& expenses) {
    if (expenses.empty()) {
        std::cout << RED << "No expenses to remove.\n" << RESET;
        return;
    }

    std::cout << "Expenses:\n";
    for (size_t i = 0; i < expenses.size(); i++) {
        std::cout << i+1 << ". " << expenses[i].category << " - $" << expenses[i].amount << "\n";
    }

    std::cout << "Enter the number of the expense to remove: ";
    size_t index;
    std::cin >> index;

    if (index < 1 || index > expenses.size()) {
        std::cout << RED << "Invalid index.\n" << RESET;
        return;
    }

    expenses.erase(expenses.begin() + (index - 1));
    std::cout << GREEN << "Expense removed successfully!\n" << RESET;
}
void viewExpenses(const std::vector<Expense>& expenses) {
    if (expenses.empty()) {
        std::cout << RED << "No expenses recorded.\n" << RESET;
        return;
    }

    std::cout << BOLD << "All Expenses:\n" << RESET;
    for (const auto& e : expenses) {
        std::cout << "- " << CYAN << e.category << RESET << ": $" << e.amount << "\n";
    }
}
void showTotal(const std::vector<Expense>& expenses) {
    double total = 0;
    for (const auto& e : expenses) {
        total += e.amount;
    }
    std::cout << BOLD << "Total Spent: " << RESET << GREEN << "$" << total << "\n" << RESET;
}
void showByCategory(const std::vector<Expense>& expenses) {
    if (expenses.empty()) {
        std::cout << RED << "No expenses recorded.\n" << RESET;
        return;
    }

    std::map<std::string, double> categoryTotals;
    for (const auto& e : expenses) {
        categoryTotals[e.category] += e.amount;
    }

    std::cout << BOLD << "Spending by Category:\n" << RESET;
    for (const auto& pair : categoryTotals) {
        std::cout << CYAN << pair.first << RESET << ": $" << pair.second << "\n";
    }
}
void saveToFile(const std::vector<Expense>& expenses, const std::string& filename) {
    std::ofstream out(filename);
    for (const auto& e : expenses) {
        out << e.category << " " << e.amount << "\n";
    }
}
void loadFromFile(std::vector<Expense>& expenses, const std::string& filename) {
    std::ifstream in(filename);
    Expense e;
    while (in >> e.category >> e.amount) {
        expenses.push_back(e);
    }
}

int main() {
    std::vector<Expense> expenses;
    const std::string filename = "expenses.txt";

    loadFromFile(expenses, filename);

    int selection;
    do {
        std::cout << "\n==== Expense Tracker ====\n";
        std::cout << "1. Add Expense\n";
        std::cout << "2. Remove Expense\n";
        std::cout << "3. View All Expenses\n";
        std::cout << "4. Show Total Spent\n";
        std::cout << "5. Show Spending by Category\n";
        std::cout << "6. Exit\n";
        std::cout << "Please select an option: ";
        std::cin >> selection;

        switch (selection) {
            case 1: addExpense(expenses); break;
            case 2: removeExpense(expenses); break;
            case 3: viewExpenses(expenses); pause(); break;
            case 4: showTotal(expenses); pause(); break;
            case 5: showByCategory(expenses); pause(); break;
            case 6: saveToFile(expenses, filename); std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n"; pause(); break;
        }
    } while (selection != 6);

    return 0;
}