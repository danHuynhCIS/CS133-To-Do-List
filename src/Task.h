#ifndef TASK_H
#define TASK_H
#include <iostream>

class Task {
private:
    std::string task;
    int priority; // range of values [0, 1, 2, ..., n], with 0 as highest priority
    bool isComplete = false; // default is not complete

public:
    Task(std::string task, int priority);
    Task(std::string task);
    Task();

    std::string getTask();
    void setTask(std::string newTask);

    int getPriority();
    void setPriority(int newPriority);
    bool getIsComplete();
    void setIsComplete(bool complete);

};

#endif
