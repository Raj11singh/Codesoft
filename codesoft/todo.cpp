#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

vector<Task> tasks;

void addTask() {
    cout << "Enter the task description: ";
    string desc;
    cin.ignore();
    getline(cin, desc);
    tasks.push_back(Task(desc));
    cout << "Task added successfully.\n";
}

void viewTasks() {
    if (tasks.empty()) {
        cout << "No tasks available.\n";
        return;
    }
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << endl;
    }
}

void markTaskAsCompleted() {
    if (tasks.empty()) {
        cout << "No tasks available to mark as completed.\n";
        return;
    }
    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks[taskNumber - 1].completed = true;
    cout << "Task marked as completed.\n";
}

void removeTask() {
    if (tasks.empty()) {
        cout << "No tasks available to remove.\n";
        return;
    }
    cout << "Enter the task number to remove: ";
    int taskNumber;
    cin >> taskNumber;
    if (taskNumber < 1 || taskNumber > tasks.size()) {
        cout << "Invalid task number.\n";
        return;
    }
    tasks.erase(tasks.begin() + taskNumber - 1);
    cout << "Task removed successfully.\n";
}

void displayMenu() {
    cout << "\nTo-Do List Manager\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    bool running = true;
    while (running) {
        displayMenu();
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                running = false;
                cout << "Exiting To-Do List Manager.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
    return 0;
}
