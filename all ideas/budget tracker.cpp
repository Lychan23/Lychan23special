#include <iostream>
#include <vector>
using namespace std;

struct BudgetItem {
    string name;
    double amount;
    string category;
    string date;
};

vector<BudgetItem> budgetItems;

void addBudgetItem() {
    BudgetItem item;
    cin.ignore(); // Ignore the newline character in the input buffer
    cout << "Enter name: ";
    getline(cin, item.name);
    cout << "Enter amount: ";
    cin >> item.amount;
    cin.ignore(); // Ignore the newline character in the input buffer
    cout << "Enter category: ";
    getline(cin, item.category);
    cout << "Enter date: ";
    getline(cin, item.date);

    budgetItems.push_back(item);
}

void displayBudgetItems() {
    for (int i = 0; i < budgetItems.size(); ++i) {
        cout << "Name: " << budgetItems[i].name << endl;
        cout << "Amount: " << budgetItems[i].amount << endl;
        cout << "Category: " << budgetItems[i].category << endl;
        cout << "Date: " << budgetItems[i].date << endl;
        cout << endl;
    }
}

double calculateTotalExpenses() {
    double total = 0.0;
    for (int i = 0; i < budgetItems.size(); ++i) {
        total += budgetItems[i].amount;
    }
    return total;
}

void generateReport() {
    cout << "Budget Report" << endl;
    cout << "------------------------" << endl;
    cout << "Total Expenses: " << calculateTotalExpenses() << endl;
    cout << endl;
}

void displayMenu() {
    cout << "Personal Budget Tracker" << endl;
    cout << "------------------------" << endl;
    cout << "1. Add Budget Item" << endl;
    cout << "2. Display Budget Items" << endl;
    cout << "3. Generate Report" << endl;
    cout << "4. Exit" << endl;
    cout << "------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addBudgetItem();
                break;
            case 2:
                displayBudgetItems();
                break;
            case 3:
                generateReport();
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << endl;
    } while (choice != 4);

    return 0;
}

