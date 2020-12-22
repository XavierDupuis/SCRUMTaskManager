#include "Iteration.h"

Iteration::Iteration() : totalWeight(0), id(Counter++)
{
}

unsigned Iteration::Counter = 0;

void Iteration::addTask(const Task* taskPtr)
{
    totalWeight += taskPtr->weight;
    tasks.push_back(taskPtr);
}

std::ostream& operator<<(std::ostream& out, const Iteration& iteration)
{
    out << "Iteration " << iteration.id << " : ";
    for (auto& task : iteration.tasks)
    {
        out << "    " << task->name << std::endl;
    }
    return out;
}