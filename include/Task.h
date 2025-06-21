#include <cstddef>
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream> //Include for file interactions
using namespace std;

class Task {
    public:
        string description;
        bool isDone;
        string stat;

        void mark();
        void print(int index);
        std::string serialize() const;
        std::string status(int indicator);
        static Task deserialize(const std::string& line);

        Task(string desc) : description(desc), isDone(false), stat("Pending") {}
};