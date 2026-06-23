# taskman

A command-line task manager written in C++17. Built as a structured learning project covering core C++ concepts including structs, enums, vectors, file I/O, iterators, and CLI argument parsing.

## features

- add tasks with optional due dates and priority levels
- list all tasks or filter by status
- sort tasks by priority or due date
- mark tasks as done
- delete tasks
- persistent storage via CSV

## requirements

- g++ 11 or later
- CMake 3.22 or later

## build

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

## usage

```bash
# add a task
./taskman add "Buy groceries" --due 2026-06-15 --priority high

# list all tasks
./taskman list

# filter tasks
./taskman list --filter pending
./taskman list --filter done

# sort tasks
./taskman list --sort priority
./taskman list --sort due

# mark a task as done
./taskman done <id>

# delete a task
./taskman delete <id>
```

## project structure
```
taskman/

├── CMakeLists.txt

├── data/

│   └── tasks.csv

├── include/

│   ├── task.h

│   └── task_manager.h

└── src/

├── main.cpp

└── task_manager.cpp
```

## concepts covered

- structs and enums
- classes and encapsulation
- vectors and iterators
- file I/O with fstream
- CLI argument parsing with argc/argv
- std::find_if, std::copy_if, std::sort
- exception handling with try/catch

## license

MIT