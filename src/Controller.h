#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "TaskManager.h"

class Controller 
{
public:
    Controller(TaskManager& taskManager);

    bool inputAndAddTask();
    bool removeTask();

private:
    template<typename T>
    T input(std::string query);

    TaskManager& taskManager_;
};

#endif // CONTROLLER_H