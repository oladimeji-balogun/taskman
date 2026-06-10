#include <iostream>
#include "task_manager.h"
#include "task.h"

int main(int argc, char* argv[]) {
    
    TaskManager manager;
    manager.loadTasks();

    // manager.addTask("Buy groceries", "2026-06-15", Priority::High);
    // manager.addTask("Read a book", "2026-06-20", Priority::Low);
    // manager.addTask("Fix a bug #433", "2026-06-12", Priority::Medium);

   if (argc < 2) {
    std::cout << "usage: taskman <command> [options]\n";
    std::cout << "commands: add, list, done, delete\n"; 
    return 1;
   } // to make the user know the valid commands to type

   std::string command = argv[1]; // accept the command

   // process the commands 
   if (command == "list") {
    manager.listTasks();
   } else if (command == "add") {
        if (argc < 3) {
            // this will force the user to pass in all the required parameters for the add command to work
            std::cout << "usage: ./taskman add <title> [--due 12-12-2026] [--priority high|medium|low]\n";
            return 1;
        }

        std::string title = argv[2];
        std::string due_date = ""; 
        Priority priority = Priority::High;

        // mapping the the arguments to their their correponding variables 
        for (int i = 3; i < argc; i++) {
            std::string arg = argv[i];

            if (arg == "--due" && i + 1 < argc) {
                due_date = argv[++i];
            } else if (arg == "--prioriry" && i + 1 < argc){
                std::string p = argv[++i];

                if (p == "low") priority = Priority::Low;
                else if (p == "medium") priority = Priority::Medium;
                else priority = Priority::High;
            }
        }

        manager.addTask(title, due_date, priority);
        manager.saveTasks();
        std::cout << "task saved successfully.\n";

   } else {
        std::cout << "unknown command: " << command << "\n"; 
        return 1; 
   }

    return 0;
}