#include "Iteration.h"

Iteration::Iteration() : totalWeight(0)
{
}

void Iteration::addTask(const Task* taskPtr)
{
    totalWeight += taskPtr->weight;
    tasks.push_back(taskPtr);
}

std::ostream& operator<<(std::ostream& out, const Iteration& iteration)
{
    for (auto& task : iteration.tasks)
    {
        out << task->id << " ";
    }
    return out;
}