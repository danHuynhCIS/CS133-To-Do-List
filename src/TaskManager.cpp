#include "TaskManager.h"

TaskManager::TaskManager() {
    head = nullptr;

}

void TaskManager::addTask(Task task) {
    taskPQ.push(new TaskNode(task));
}

void TaskManager::createLinkedList() {
    if (head != nullptr) {
        deleteLinkedList();
    }

    head = taskPQ.top();
    taskPQ.pop();
    TaskNode* curr = head;

    while(!taskPQ.empty()) {
        curr->next = taskPQ.top();
        taskPQ.pop();
        curr = curr->next;
    }
    curr->next = nullptr;
}

TaskNode* TaskManager::traverse(int index) {
    TaskNode* curr = head;
    for(int i = 0; i < index; i++){
        curr = curr->next;
    }
    return curr;
}

TaskNode* TaskManager::getHead() {
    return head;
}

void TaskManager::deleteLinkedListHelper(TaskNode* curr) {
    // return if list is empty
    if (curr == nullptr) {
        return;
    }

    addTask(curr->task);
    // delete next node recursively
    deleteLinkedListHelper(curr->next);

    // delete current node
    delete curr;
}

void TaskManager::deleteLinkedList(){
    if (head == nullptr){
        return;
    }

    deleteLinkedListHelper(head);

}

void TaskManager::completedTask(int index){
    TaskNode* completedTask = traverse(index);
    completedTask->task.setIsComplete(true);
}

void TaskManager::setPriority(int index, int newPriority) {
    TaskNode* priorityNode = traverse(index);
    priorityNode->task.setPriority(newPriority);
    deleteLinkedList();
    createLinkedList();
}


void TaskManager::setTask(int index, std::string newTask){
    TaskNode* taskNode = traverse(index);
    taskNode->task.setTask(newTask);
}

void TaskManager::printTasks() {

    TaskNode* curr = head;
    int index = 0;

    while (curr != nullptr) {
        std::cout << "Task " << index++ << ": "
                  << curr->task.getTask()
                  << " | Priority: " << curr->task.getPriority()
                  << " | Completed: " << (curr->task.getIsComplete() ? "Yes" : "No")
                  << std::endl;
        curr = curr->next;
    }
}

TaskManager::~TaskManager() {
    deleteLinkedList();
}
