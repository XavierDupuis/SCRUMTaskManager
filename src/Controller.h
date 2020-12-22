#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>

#include "TaskManager.h"
#include "ExceptTaskNotFound.h"
#include "ExceptInvalidInput.h"

class Controller 
{
public:
    Controller(TaskManager& taskManager);

    bool menu();

    bool inputAndAddTask();
    bool removeTask();

private:
    template<typename T>
    T input(std::string query);

    std::pair<unsigned, std::string> options_ = {5," 0 - Exit \n 1 - Displays tasks \n 2 - Add a task \n 3 - Edit a task \n 4 - Remove a task"};

    TaskManager& taskManager_;
};

#endif // CONTROLLER_H