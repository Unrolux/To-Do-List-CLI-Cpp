#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include <fstream> //Include for file interactions
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

    std::string serialize() const {
        return (isDone ? "1" : "0") + std::string(";") + description;
    }

    static Task deserialize(const std::string& line) {
        size_t sep = line.find(';');
        bool done = line[0] == '1';
        std::string desc = line.substr(sep + 1);
        Task task(desc);
        task.isDone = done;
        return task;
    }
};

int main() {
    vector<Task> tasks;  // Dynamic list of Task objects

    std::ifstream in("tasks.txt");
    std::string line;
    while (std::getline(in, line)) {
        if(!line.empty()) {
            tasks.push_back(Task::deserialize(line));
        }
    }
    in.close();

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
            std::ofstream out("tasks.txt");
            for (const Task& task : tasks) {
                out << task.serialize() << '\n';
            }
            out.close();
            cout << "Saved & Exiting...\n";
            break;

        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

