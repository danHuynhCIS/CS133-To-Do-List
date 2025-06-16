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

    void deleteLinkedListHelper(TaskNode* curr);


public:
    TaskManager();
    ~TaskManager();

    // adds a new TaskNode to the PQ
    void addTask(Task task);

    // sets the task at the given index of the linked list as complete
    void completedTask(int index);

    // recursively traverses the linked list, deleting each node from memory
    void deleteLinkedList();

    // creates the linked list of tasknodes from each tasknode stored in the PQ
    void createLinkedList();

    TaskNode* getHead();

    // sets the priority of a Task/TaskNode at the given index in the list
    void setPriority(int index, int newPriority);

    // sets a new name for the task at the given index
    void setTask(int index, std::string newTask);
    
    void printTasks();
};

#endif
