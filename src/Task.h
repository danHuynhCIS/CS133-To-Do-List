#ifndef TASK_H
#define TASK_h
#include <iostream>

class Task {
private:
    std::string task;
    int priority; // range of values [0, 1, 2, ..., n], with 0 as highest priority

public:
    Task(std::string task, int priority);
    Task(std::string task);

    std::string getTask();
    void setTask(std::string newTask);

    int getPriority();
    void setPriority(int newPriority);
    
};

#endif