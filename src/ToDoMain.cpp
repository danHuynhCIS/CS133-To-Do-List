#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include "TaskManager.h"
#include "FileManager.h"
#include <string>

void taskAdder(TaskManager &taskManager);

void intro() {
    std::cout << "==============================" << std::endl;
    std::cout << "      C++ To-Do List App      " << std::endl;
    std::cout << "==============================" << std::endl;
    std::cout << "This app allows you to manage your tasks with priorities." << std::endl;
    std::cout << "You can add tasks, set their priorities, and mark them as complete." << std::endl;
}

bool isValidInteger(const std::string& s) {
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
    }
    
    return true;
}

void saveToFile(const std::string &prompt, TaskManager &taskManager){
    std::cout << "Enter the name of a .txt file: ";
    std::string fileName;

    getline(std::cin, fileName);
    std::cout << std::endl;

    FileManager fileManager(&taskManager);

    fileManager.saveFile(fileName);
}

void otherChoices(TaskManager &taskManager, bool& exitProgram) {
    std::string choice;
    int index;
    std::string newTask;
    int newPriority;

    while (true) {
        std::cout << "Choose an option: " << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "1. View Tasks" << std::endl;
        std::cout << "2. Mark Task as Complete" << std::endl;
        std::cout << "3. Add More Tasks" << std::endl;
        std::cout << "4. Set Task Priority" << std::endl;
        std::cout << "5. Set Task Name" << std::endl;
        std::cout << "==============================" << std::endl;
        std::cout << "6. Save As" << std::endl; 
        std::cout << "7. Exit" << std::endl;
        std::cout << std::endl;
        std::cout << "Enter choice: ";
        getline(std::cin, choice);
        std::cout << std::endl;

        if (choice == "1") {
            taskManager.printTasks();
            std::cout << std::endl;

        } else if (choice == "2") {
            taskManager.printTasks();
            std::cout << std::endl;
            std::cout << "Enter the task number to mark as complete: ";
            std::cin >> index;
            std::cin.ignore();
            taskManager.completedTask(index);
            std::cout << "Task marked as complete." << std::endl;

        } else if (choice == "3") {
            taskAdder(taskManager);
            // std::cout << "coming back" << std::endl;

        } else if (choice == "4") {
            taskManager.printTasks();
            std::cout << std::endl;
            std::cout << "Enter the index of the task to set priority: ";
            std::cin >> index;
            std::cin.ignore();
            std::cout << "Enter new priority: ";
            std::cin >> newPriority;
            std::cin.ignore();
            taskManager.setPriority(index, newPriority);
            std::cout << "New priority set." << std::endl;

        } else if (choice == "5") {
            taskManager.printTasks();
            std::cout << std::endl;
            std::cout << "Enter the index of the task to set name: ";
            std::cin >> index;
            std::cin.ignore();
            std::cout << "Enter new task name: ";
            getline(std::cin, newTask);
            taskManager.setTask(index, newTask);
            std::cout << "New name set." << std::endl;

        } else if (choice == "6") {
            /* std::cout << "Enter the name of a .txt file: ";
            std::string fileName;
            getline(std::cin, fileName);
            std::cout << std::endl;
            FileManager fileManager(&taskManager);
            fileManager.saveFile(fileName);
            std::cout << "File saved!" << std::endl;
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            exitProgram = true;
            return; */

            saveToFile("Enter the name of a .txt file: ", taskManager);

        } else if (choice == "7") {
            std::cout << "Exiting the program. Goodbye!" << std::endl;
            exitProgram = true;
            return;

        } else {
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
}

void loadFromFile(const std::string &prompt, TaskManager &taskManager) {
    std::cout << "Enter the name of a .txt file: ";
    std::string fileName;

    getline(std::cin, fileName);
    std::cout << std::endl;

    FileManager fileManager(&taskManager);

    fileManager.loadFile(fileName);

    taskManager.createLinkedList();
}

void taskAdder(TaskManager &taskManager) {
    std::string taskName;
    std::string priority;
    bool addTasks = false;

    while (!addTasks) {

        std::cout << "Enter task name (done to exit): ";
        getline(std::cin, taskName);

        if (taskName == "done" || taskName == "Done") {
            std::cout << "Done adding tasks." << std::endl;
            addTasks = true;
        }
        if (taskName != "done"){
            std::cout << "Enter task priority (done to exit): ";
            getline(std::cin, priority);
        }
        if (priority == "done" || priority == "Done") {
            std::cout << "Done adding tasks." << std::endl;
            taskManager.addTask(Task(taskName, 0));
            addTasks = true;
        }
        if (!addTasks) {
            while (!isValidInteger(priority)) {
                std::cout << "Invalid input. Please enter a valid integer for priority: ";
                getline(std::cin, priority);
            }
            taskManager.addTask(Task(taskName, std::stoi(priority)));
        }
    }
    
    taskManager.createLinkedList();
    
    
}

void systemProcess(TaskManager& TaskManager, bool& exitProgram) {

    std::cout << "Do you want to load tasks from a file? (y/n): ";
    std::string choice;
    getline(std::cin, choice);
    std::cout << std::endl;

    if (choice[0] == 'y' || choice[0] == 'Y') {
        loadFromFile("Enter the name of a file: ", TaskManager);
    } 
    else if (choice[0] == 'n' || choice[0] == 'N') {
        taskAdder(TaskManager); 
         
    } 
    else {
        std::cout << "Invalid choice. Please enter 'y' or 'n'." << std::endl;
        return;
    }
}

int main() {

    intro();
    
    bool exitProgram = false;
    TaskManager taskManager;
    

    systemProcess(taskManager, exitProgram);

    while (!exitProgram) {
        
        otherChoices(taskManager, exitProgram); 
    }
    
    return 0;
}
