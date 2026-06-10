#include <iostream>
#include "task_manager.h"

int main() {
    // 
    
    TaskManager manager;
    manager.addTask("Buy groceries", "2026-06-15", Priority::High);
    manager.addTask("Read a book", "2026-06-20", Priority::Low);
    manager.addTask("Fix a bug #433", "2026-06-12", Priority::Medium);

    manager.listTasks();

    return 0;
}