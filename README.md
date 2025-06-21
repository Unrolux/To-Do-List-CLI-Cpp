# 📝 Todo CLI App (C++)

A simple command-line To-Do list application built in C++ to help you manage daily tasks, save your progress, and learn the fundamentals of object-oriented programming, file I/O, and modular C++ development.

---

## 🚀 Features

- Add, view, remove, and mark tasks
- Change task status: Pending / In Progress / Completed
- Automatically saves and loads tasks from a file
- Clean modular code (with `Task` and `Utils` classes)
- CMake support for easy builds
- Tasks are saved in a file named `tasks.txt` in the project directory.
- They are automatically loaded when you start the app again.

---

## 🗂️ Sample Output
```bash
=== To-Do Menu ===
1. Add Task
2. View Tasks
3. Remove Task
4. Mark Task
5. Status Change
0. Exit
Choice: 
```

---

## 🔧 Build Instructions

### ✅ With CMake (Recommended)

1. Make sure CMake is installed:
   - Arch: `sudo pacman -S cmake`
   - Ubuntu: `sudo apt install cmake`
   - Windows: [Install from official site](https://cmake.org/)

2. Build the app:

```bash
git clone https://github.com/Unrolux/To-Do-List-CLI-Cpp.git
cd To-Do-List-CLI-Cpp
mkdir build
cd build
cmake ..
make 
```
## With C++ compiler (Directly)

### Linux

1. C++ compiler is installed by default in most Linux distributions.

2. Build the app:
```bash
git clone https://github.com/Unrolux/To-Do-List-CLI-Cpp.git
cd To-Do-List-CLI-Cpp
g++ -Iinclude src/* include/* main.cpp -o todo
./todo
```
### Windows

1. Make sure to have a C++ compiler installed and added to PATH. [Recommended](https://sourceforge.net/projects/mingw/) 
2. Download files or clone via git.
3. Open Powershell or preferred terminal emulator in cloned folder.
4. Build the app:
```bash
g++ -Iinclude .\src\* .\include\* main.cpp -o todo
.\todo.exe
```

### 📘 Learning Goals

This project was built as a way to practice:
- Object-Oriented Programming in C++
- Pointers, references, and memory management
- File I/O and data persistence
- Codebase structuring and modular development
- Using CMake for modern C++ builds

### 🧑‍💻 Author

Made by Unrolux