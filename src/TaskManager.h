#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <algorithm>
#include <vector>
#include <memory>
#include "Task.h"

class TaskManager
{
public:
    TaskManager();
    
    bool AddTask(Task& task);
    bool UpdateTask(Task& task);
    bool RemoveTask(Task& task);

// remove next commented line
//private:
    std::vector<std::unique_ptr<Task>> tasks_;
};

#endif