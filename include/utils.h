#pragma once
#include "fstream"
#include <vector>
#include "Task.h"

using namespace std;

class Utils {
    public:
    static void load(vector<Task>& file);
    static void save(const vector<Task>& file);
};