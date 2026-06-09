#include <iostream>
#include "task.h"

int main() {
    Task t;
    t.id = 1;
    t.title = "Buy groceeries"; 
    t.due_date = "2026-06-15";
    t.priority = Priority::High;
    t.done = false;

    std::boolalpha;
    std::cout << "ID: " << t.id << "\n"; 
    std::cout << "Title: " << t.title << "\n"; 
    std::cout << "Due: " << t.due_date << "\n"; 
    std::cout << "DOne: " << t.done << "\n";

    return 0;
}