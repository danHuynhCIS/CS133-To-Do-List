#include <iostream>
#include "TaskManager.h"

void intro() {

}


int main() {

    //intro();
    TaskManager taskManager;
    taskManager.addTask(Task("Complete C++ project", 2));
    taskManager.addTask(Task("Review code", 1));
    taskManager.createLinkedList();
    taskManager.printTasks();

    return 0;
}