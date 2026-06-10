#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <task.h>

class TaskManager {
    public:
        void addTask(const std::string& title, const std::string& due_date, Priority priority);

        void listTasks() const;

    private:
        std::vector<Task> tasks;
        int next_id = 1;
};
#endif

