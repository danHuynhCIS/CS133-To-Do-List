#include "FileManager.h"
#include "Task.h"
#include <filesystem>
#include <string>

FileManager::FileManager(TaskManager* tasks) : tasks(tasks) {}

void FileManager::loadFile(std::string inputFile) {

    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << inputFile << std::endl;
        return;
    }

    std::string line;
    std::string priority;
    while (std::getline(file, line)) {
        std::getline(file, priority);
        tasks->addTask(Task(line, std::stoi(priority)));
    }

    std::cout << "File loaded!" << std::endl;

    file.close();
}

void FileManager::saveFile(const std::string& outputFile) {
    std::ofstream file(outputFile);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << outputFile << std::endl;
        return;
    }

    TaskNode* curr = tasks->getHead();
    while (curr != nullptr) {
        file << curr->getTask() << std::endl;
        file << curr->getPriority() << std::endl;
        curr = curr->next;
    }

    std::cout << "File saved!" << std::endl;

    file.close();
}
