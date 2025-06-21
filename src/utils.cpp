#include "../include/utils.h"
#include "../include/Task.h"
#include "fstream"

void Utils::load(vector<Task>& file) {
    std::ifstream in("tasks.txt");
    std::string line;
    while (std::getline(in, line)) {
        if(!line.empty()) {
            file.push_back(Task::deserialize(line));
        }
    }
    in.close();
}

void Utils::save(const vector<Task>& file) {
    std::ofstream out("tasks.txt");
    for (const Task& task : file) {
        out << task.serialize() << '\n';
    }
    out.close();
}