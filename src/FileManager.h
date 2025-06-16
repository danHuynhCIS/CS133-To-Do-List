#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include <filesystem>
#include "TaskManager.h"

class FileManager {
private:
    TaskManager* tasks;
public:
    FileManager(TaskManager* tasks);

    // loads a to-do list to the FileManager's TaskManager from the given .txt file
    void loadFile(std::string inputFile);

    // saves the to-do list from the TaskManager to the given .txt file
    void saveFile(const std::string& outputFile);
    
    void deleteFile(const std::string& filename);
};

#endif
