#include "../include/Task.h"
using namespace std;

// Represents one task
void Task::mark() {
    isDone = !isDone;
}

void Task::print(int index) {
    cout << index << ". [" << (isDone ? "x" : " ") << "] " << description << " : "<< stat << '\n';
}

std::string Task::serialize() const {
    return (isDone ? "1" : "0") + std::string(";") + description + std::string(":") + stat;
}

std::string Task::status(int indicator) {
    if (indicator == 1) {
        return stat = "Pending";
    } else if (indicator == 2) {
        return stat = "Completed";
    } else if (indicator == 3) {
        return stat = "In Progress";
    } else {
        return stat = "Not defined";
    }
    return stat;
}

Task Task::deserialize(const std::string &line) {
    size_t sep = line.find(';');
    size_t sep2 = line.find(':');
    bool done = line[0] == '1';
    std::string desc = line.substr(sep + 1, sep2);
    Task task(desc);
    std::string status = line.substr(sep2 + 1);
    task.stat = status;
    task.isDone = done;
    return task;
}
