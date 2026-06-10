#include <task_manager.h>
#include <iostream>

void TaskManager::addTask(const std::string& title, const std::string& due_date, Priority priority) {
    Task t;
    t.id = next_id++;
    t.title = title;
    t.due_date = due_date;
    t.priority = priority;
    t.done = false;

    tasks.push_back(t);
}

void TaskManager::listTasks() const {
    if (tasks.empty()) {
        std::cout << "no tasks found. \n";
        return;
    }

    for (const Task& t: tasks) {
        std::cout << "[" << t.id << "] "
            << t.title
            << " | due: " << t.due_date
            << " | priority: " << priorityToString(t.priority)
            << " | done: " << std::boolalpha << t.done
            << "\n";
    }
}