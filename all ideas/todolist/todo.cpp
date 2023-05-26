#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

struct Task {
    std::string title;
    std::string description;
};

void displayMenu() {
    std::cout << "=== Todo List Application ===" << std::endl;
    std::cout << "1. Add a task" << std::endl;
    std::cout << "2. View all tasks" << std::endl;
    std::cout << "3. Mark task as completed" << std::endl;
    std::cout << "4. Quit" << std::endl;
    std::cout << "=============================" << std::endl;
}

void addTask(std::vector<Task>& tasks) {
    std::cout << "Enter task title: ";
    std::string title;
    std::getline(std::cin, title);

    std::cout << "Enter task description: ";
    std::string description;
    std::getline(std::cin, description);

    Task newTask;
    newTask.title = title;
    newTask.description = description;

    tasks.push_back(newTask);

    std::cout << "Task added successfully!" << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) {
    std::cout << "=== Task List ===" << std::endl;

    if (tasks.empty()) {
        std::cout << "No tasks found." << std::endl;
    } else {
        for (std::vector<Task>::size_type i = 0; i < tasks.size(); ++i) {
            std::cout << "Title: " << tasks[i].title << std::endl;
            std::cout << "Description: " << tasks[i].description << std::endl;
            std::cout << "------------------------" << std::endl;
        }
    }

    std::cout << "=================" << std::endl;
}

void markTaskCompleted(std::vector<Task>& tasks) {
    std::cout << "Enter the index of the task to mark as completed: ";
    int index;
    std::cin >> index;

    // Clear the newline character from the input stream
    std::cin.ignore(1000, '\n');

    bool taskFound = false; // Flag to track if the task is found

    if (index >= 0 && index < static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index);
        std::cout << "Task marked as completed!" << std::endl;
        taskFound = true;
    }

    if (!taskFound) {
        std::cout << "Invalid task index." << std::endl;
    }
}



int main() {
    std::vector<Task> tasks;

    while (true) {
        displayMenu();

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore newline character after reading the choice

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                std::cout << "Exiting the application. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}

