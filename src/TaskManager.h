#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>

#include "Task.h"

class TaskManager
{
public:
    TaskManager(unsigned iterPeriod, unsigned maxEffortByPeriod);
    
    bool AddTask(std::unique_ptr<Task> task);
    bool UpdateTask(unsigned long& id, unsigned weight, unsigned value);
    bool RemoveTask(const unsigned long& id);

    friend std::ostream& operator<<(std::ostream& out,
    				    const TaskManager& taskManager);
    
    void displayTasks();

    void createTimeTable();

private:
    void sortTasks();
    unsigned iterPeriod_;
    unsigned maxEffortByPeriod_;
    std::vector<std::unique_ptr<Task>> tasks_;
    std::vector<std::vector<std::unique_ptr<Task>>> timeTable_;
};

#endif // TASKMANAGER_H
