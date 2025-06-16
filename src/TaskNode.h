#ifndef TASKNODE_H
#define TASKNODE_h
#include <iostream>
#include "Task.h"

struct TaskNode {
    Task task;
    TaskNode* next;

    TaskNode(Task task);

    std::string getTask();
    void setTask(std::string newTask);

    int getPriority();
    void setPriority(int newPriority);
};

// used for sorting tasknodes in a priority queue
class taskCompare {
public:
    bool operator()(TaskNode* a, TaskNode* b);
};

#endif