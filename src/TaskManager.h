#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <algorithm>
#include <vector>
#include <memory>
#include <iostream>

#include "Iteration.h"
#include "Task.h"

class TaskManager
{
public:
    TaskManager(unsigned iterationWeight, unsigned iterationPeriod);
    
    bool AddTask(std::unique_ptr<Task> task);
    bool UpdateTask(unsigned long& id, unsigned weight, unsigned value);
    bool RemoveTask(const unsigned long& id);

    std::vector<std::unique_ptr<Task>>& getTasks();

    friend std::ostream& operator<<(std::ostream& out, const TaskManager& taskManager);
    void displayTasks();
    void displayTimeTable();
    
    void createTimeTable();

private:
    void sortTasks();

    unsigned iterationWeight_;
    unsigned iterationPeriod_;
    std::vector<std::unique_ptr<Task>> tasks_;

    std::vector<const Task*> orderedTasksByRatio_;
    std::vector<const Task*> tasksTooHeavy_;
    std::vector<std::unique_ptr<Iteration>> timeTable_;
};

#endif // TASKMANAGER_H
