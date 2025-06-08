#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <iostream>
#include <fstream>
#include "TaskManager.h"

class FileManager {
private:
    TaskManager taskManager;

public:
    void loadFile(const std::string& inputFile, const std::string& outputFile);

};

#endif