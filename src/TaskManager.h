#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <algorithm>
#include <vector>
#include "task.h"

class TaskManager
{
public:
    TaskManager();
    
    bool AddTask(Task& task);
    bool UpdateTask(Task& task);
    bool RemoveTask(Task& task);

// remove next commented line
//private:
    std::vector<Task> tasks_;
};

#endif