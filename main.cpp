#include <cstddef>
#include <iostream>
#include <vector>
#include <string>
#include "./include/Task.h"
#include "./include/utils.h"
using namespace std;

int main() {
    vector<Task> tasks;  
    Utils::load(tasks);
    int choice;

    while (true) {
        cout << "\n=== To-Do Menu ===\n";
        cout << "1. Add Task\n2. View Tasks\n3. Remove Task\n4. Mark Task\n5. Status Change\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;
        cin.ignore(); 

        if (choice == 1) {
            string desc;
            cout << "Enter task: ";
            getline(cin, desc); 
            tasks.emplace_back(desc); 

        } else if (choice == 2) {
            cout << "\n--- To-Do List ---\n";
            if (tasks.empty()) {
                cout << "No tasks yet!\n";
            } else {
                for (size_t i = 0; i < tasks.size(); ++i)
                    tasks[i].print(i + 1);  
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
        } else if (choice == 5) {
            int index;
            std::cout << "Enter task number to change status of: ";
            std::cin >> index;
            std::cin.ignore();
            if (index >= 1 && index <= tasks.size()) {
                int status_choice;
                std::cout << "1. Pending\n2. Completed\n3. In Progress\nChoose from the following (number): ";
                std::cin >> status_choice;
                std::cin.ignore();
                tasks[index-1].status(status_choice);
            } else {
                std::cout << "Invalid Choice!\n";
            }
        } else if (choice == 0) {
            Utils::save(tasks);
            cout << "Saved & Exiting...\n";
            break;

        } else {
            cout << "Invalid choice. Try again.\n";
        }
    }
}

