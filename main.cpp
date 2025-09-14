#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <vector>

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

void addExpense(std::vector<Expense>& expenses);
void removeExpense(std::vector<Expense>& expenses);
void viewExpenses(const std::vector<Expense>& expenses);
void showTotal(const std::vector<Expense>& expenses);
void showByCategory(const std::vector<Expense>& expenses);
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
            case 3: viewExpenses(expenses); break;
            case 4: showTotal(expenses); break;
            case 5: showByCategory(expenses); break;
            case 6: saveToFile(expenses, filename); std::cout << "Goodbye!\n"; break;
            default: std::cout << "Invalid choice.\n";
        }
    } while (selection != 6);

    return 0;
}