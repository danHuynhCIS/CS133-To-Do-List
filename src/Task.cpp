#include "Task.h"

Task::Task(std::string task, int priority) {
    this->task = task;
    this->priority = priority;
}

Task::Task(std::string task) {
    this->task = task;
}

std::string Task::getTask() {
    return task;
}

void Task::setTask(std::string newTask) {
    task = newTask;
}

int Task::getPriority() {
    return priority;
}

void Task::setPriority(int newPriority) {
    priority = newPriority;
}