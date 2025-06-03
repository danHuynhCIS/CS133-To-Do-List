#ifndef TASKMANAGER_H
#define TASKMANAGER_H
#include <iostream>
#include <queue>
#include <vector>
#include "TaskNode.h"


class TaskManager {
private:
    TaskNode* head;
    std::priority_queue<TaskNode*, std::vector<TaskNode*>, taskCompare> taskPQ;
    
    TaskNode* traverse(int index);
    void deleteLinkedList();

public:
    TaskManager();
    ~TaskManager();

    void addTask(Task task);
    void completedTask(int index);
    void createLinkedList();
    void setPriority(int index, int newPriority);
    void setTask(int index, std::string newTask);
    void printTasks();
};

#endif