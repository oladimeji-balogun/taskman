#ifndef TASK_H
#define TASK_H

#include <string>

enum class Priority {
    Low, 
    Medium, 
    High
};

struct Task {
    int id;
    std::string title;
    std::string due_date;
    Priority priority;
    bool done;
}; 

inline std::string priorityToString(Priority p) {
    switch (p) {
        case Priority::Low: return "Low";
        case Priority::Medium: return "Medium";
        case Priority::High: return "High";
        default: return "Unknown";

    }
}

#endif