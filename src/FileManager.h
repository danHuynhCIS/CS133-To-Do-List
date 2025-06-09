#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include "TaskManager.h"

class FileManager {
private:
    TaskManager* tasks;
public:
    FileManager(TaskManager* tasks);
    void loadFile(const std::string& inputFile);
    void saveFile(const std::string& outputFile);
    void deleteFile(const std::string& filename);
};

#endif
