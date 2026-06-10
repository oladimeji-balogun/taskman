#include <task_manager.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>


const std::string TaskManager::FILE_PATH = "../data/tasks.csv"; 

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

void TaskManager::saveTasks() const {
    std::ofstream file(FILE_PATH); 

    if (!file.is_open()){
        std::cerr << "error: could not open file for writing.\n";
        return;
    }

    for (const Task& t : tasks) {
        file << t.id << ","
            << t.title << ","
            << t.due_date << ","
            << priorityToString(t.priority) << ","
            << t.done << "\n";
    }
}

void TaskManager::loadTasks() {
    std::ifstream file(FILE_PATH);

    if (!file.is_open()) {
        // std::cerr << "error: could not open file for reading.\n";

        return;
    }

    tasks.clear();
    next_id = 1;

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string id, title, due_date, priority, done;

        std::getline(ss, id, ',');
        std::getline(ss, title, ',');
        std::getline(ss, due_date, ',');
        std::getline(ss, priority, ',');
        std::getline(ss, done, ',');

        Task t;
        t.id = std::stoi(id);
        t.title = title;
        t.due_date = due_date;
        t.priority = (priority == "High") ? Priority::High : 
                     (priority == "Medium") ? Priority::Medium : 
                     Priority::Low;

        t.done = (done == "1");

        // push the task to the tasks vector
        tasks.push_back(t);
        next_id = t.id + 1;

    }
}


void TaskManager::markDone(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [&id] (Task t) {
        return t.id == id;
    });

    if (it == tasks.end()){
        std::cout << "task " << id << " is not found.\n";
        return;
    }

    it->done = true;
    saveTasks();
    std::cout << "task " << id << "marked done successfully.\n";
}

void TaskManager::deleteTask(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(), [&id](Task t) {
        return t.id == id;
    });

    if (it == tasks.end()) {
        std::cout << "task " << id << " not found.\n"; 
        return;
    }

    tasks.erase(it);
    saveTasks();
    std::cout << "task " << id << " deleted successfully.\n";
}
