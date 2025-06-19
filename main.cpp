#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Represents one task
class Task {
public:
    string description;
    bool isDone;

    Task(string desc) : description(desc), isDone(false) {}

    void mark() {
        isDone = !isDone;
    }

    void print(int index) const {
        cout << index << ". [" << (isDone ? "x" : " ") << "] " << description << '\n';
    }
};

int main() {
    vector<Task> tasks;  // Dynamic list of Task objects
    int choice;

    while (true) {
        cout << "\n=== To-Do Menu ===\n";
        cout << "1. Add Task\n2. View Tasks\n3. Remove Task\n4. Mark Task\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline after number input

        if (choice == 1) {
            string desc;
            cout << "Enter task: ";
            getline(cin, desc);  // Read entire line including spaces
            tasks.emplace_back(desc); // Add task to vector

        } else if (choice == 2) {
            cout << "\n--- To-Do List ---\n";
            if (tasks.empty()) {
                cout << "No tasks yet!\n";
            } else {
                for (size_t i = 0; i < tasks.size(); ++i)
                    tasks[i].print(i + 1);  // Show index starting from 1
            }
        
        }else if (choice == 3) {
            if (tasks.empty()) {
                std::cout << "No tasks to REMOVE!\n";
            } else {
                int index;
                std::cout << "Enter task number: ";
                std::cin >> index;
                std::cin.ignore();

                if (index >=1 && index<=tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                    std::cout << "Task removed!\n";
                } else {
                    std::cout << "Invalid number!\n";
                }
            }
        } else if (choice == 4) {
            int index;
            std::cout << "Enter Task number to mark: ";
            std::cin >> index;
            std::cin.ignore();

            if (index >=1 && index <= tasks.size()) {
                tasks[index-1].mark();
                std::cout << "Task Marked!\n";
            } else {
                std::cout << "Invalid Choice!\n";
            }
        } else if (choice == 0) {
            cout << "Exiting...\n";
            break;

        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

