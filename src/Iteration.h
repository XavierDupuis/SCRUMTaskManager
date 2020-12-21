#ifndef ITERATION_H
#define ITERATION_H

#include <string>
#include <vector>

#include "Task.h"

struct Iteration
{
    Iteration() : totalWeight(0) {}

    void addTask(const Task* taskPtr)
    {
        totalWeight += taskPtr->weight;
        tasks.push_back(taskPtr);
    }
    
    int totalWeight;
    std::vector<const Task*> tasks;
};

#endif // ITERATION_H