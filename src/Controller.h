#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "TaskManager.h"

class Controller 
{
public:
    bool inputTask(TaskManager& taskManager);

private:
    template<typename T>
    T inputValue(std::string query);

};

#endif // CONTROLLER_H