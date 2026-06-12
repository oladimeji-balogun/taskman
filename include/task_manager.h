#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <task.h>
#include <algorithm>

class TaskManager {
    public:
        void addTask(const std::string& title, const std::string& due_date, Priority priority);

        void listTasks(const std::string& filter = "", const std::string& sort_by = "") const;
        void saveTasks() const;
        void loadTasks();
        void markDone(int id);
        void deleteTask(int id);

    private:
        std::vector<Task> tasks;
        int next_id = 1;

        static const std::string FILE_PATH;
};

#endif

