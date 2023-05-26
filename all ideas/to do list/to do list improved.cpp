#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Task {
    string description;
    bool completed;
};

// Function to display the main menu
void displayMenu() {
    cout << "To-Do List\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Search Task\n";
    cout << "4. Mark Task as Complete\n";
    cout << "5. Delete Task\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "Enter task description: ";
    getline(cin >> ws, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    cout << "Tasks:\n";
    for (int i = 0; i < tasks.size(); ++i) {
        cout << "[" << (i + 1) << "] ";
        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }
        cout << tasks[i].description << endl;
    }
}

// Function to search for a task by description
void searchTask(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    string searchDesc;
    cout << "Enter the task description to search: ";
    getline(cin >> ws, searchDesc);

    auto it = find_if(tasks.begin(), tasks.end(), [&](const Task& task) {
        return task.description == searchDesc;
    });

    if (it != tasks.end()) {
        cout << "Task found:\n";
        cout << "Description: " << it->description << endl;
        cout << "Status: " << (it->completed ? "Completed" : "Not Completed") << endl;
    } else {
        cout << "Task not found.\n";
    }
}

// Function to mark a task as complete
void markTaskAsComplete(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    int taskIndex;
    cout << "Enter the task index to mark as complete: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "Invalid task index.\n";
        return;
    }

    tasks[taskIndex - 1].completed = true;
    cout << "Task marked as complete.\n";
}

// Function to delete a task by description
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }

    int taskIndex;
    cout << "Enter the task index to delete: ";
    cin >> taskIndex;

    if (taskIndex < 1 || taskIndex > tasks.size()) {
        cout << "Invalid task index.\n";
        return;
    }

    tasks.erase(tasks.begin() + taskIndex - 1);
    cout << "Task deleted successfully!\n";
}

// Function to save tasks to a file
void saveTasksToFile(const vector<Task>& tasks, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& task : tasks) {
            file << task.description << endl;
            file << task.completed << endl;
        }
        file.close();
        cout << "Tasks saved to file.\n";
    } else {
        cout << "Unable to save tasks to file.\n";
    }
}

// Function to load tasks from a file
void loadTasksFromFile(vector<Task>& tasks, const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        tasks.clear();
        string description, completed;
        while (getline(file, description) && getline(file, completed)) {
            Task task;
            task.description = description;
            task.completed = (completed == "1");
            tasks.push_back(task);
        }
        file.close();
        cout << "Tasks loaded from file.\n";
    } else {
        cout << "No existing tasks file found.\n";
    }
}

int main() {
    vector<Task> tasks;
    const string filename = "tasks.txt";

    loadTasksFromFile(tasks, filename);

    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                searchTask(tasks);
                break;
            case 4:
                markTaskAsComplete(tasks);
                break;
            case 5:
                deleteTask(tasks);
                break;
            case 6:
                saveTasksToFile(tasks, filename);
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

        cout << endl;
    }
}

