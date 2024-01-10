#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(string desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    // Add a task to the list
    void addTask(const string& description) {
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    // Display all tasks with their status
    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list.\n";
        } else {
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << (tasks[i].completed ? "[X]" : "[ ]") << " " << tasks[i].description << endl;
            }
        }
    }

    // Mark a task as completed
    void markTaskAsCompleted(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } else {
            cout << "Invalid task index.\n";
        }
    }

    // Remove a task from the list
    void removeTask(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        cout << "\n----- TO-DO LIST MANAGER -----\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore();  // Clear the input buffer
                string taskDescription;
                cout << "Enter task description: ";
                getline(cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                toDoList.markTaskAsCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                toDoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
