#ifndef CSVHANDLER_H
#define CSVHANDLER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Task.h"
#include "TaskManager.h"
#include "ExceptBadFileAccess.h"

class CSVHandler 
{
public:
    CSVHandler(std::string filename);
    bool readFile(TaskManager& taskManager);
    bool writeFile(TaskManager& taskManager);

private:
    std::string filename_;
};

#endif //CSVHANDLER_H