#ifndef ITERATION_H
#define ITERATION_H

#include <string>
#include <vector>
#include <ostream>

#include "Task.h"

struct Iteration
{
    Iteration();

    void addTask(const Task* taskPtr);

    friend std::ostream& operator<<(std::ostream& out, const Iteration& iteration);
    
    int totalWeight;
    std::vector<const Task*> tasks;

    unsigned id;
    static unsigned Counter;
};

#endif // ITERATION_H