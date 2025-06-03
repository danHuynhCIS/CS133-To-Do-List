#include "TaskNode.h"

TaskNode::TaskNode(Task task) {
    this->task = task;
}

std::string TaskNode::getTask() {
    return task.getTask();
}

void TaskNode::setTask(std::string newTask) {
    task.setTask(newTask);
}

int TaskNode::getPriority() {
    return task.getPriority();
}

void TaskNode::setPriority(int newPriority) {
    task.setPriority(newPriority);
}

bool taskCompare::operator()(TaskNode* a, TaskNode* b) {

    // if tasks a and b priority are in ascending order, return true
    return a->task.getPriority() > b->task.getPriority();  // min heap?
}



