#include "Iteration.h"

Iteration::Iteration() : totalWeight(0), id(Counter++)
{
}

void Iteration::addTask(const Task* taskPtr)
{
    totalWeight += taskPtr->weight_;
    tasks.push_back(taskPtr);
}

std::ostream& operator<<(std::ostream& out, const Iteration& iteration)
{
    out << "  Iteration " << iteration.id << " : " << std::endl;
    for (auto& task : iteration.tasks)
    {
        out << std::left << "   "
            << std::setw(5) << task->id_ 
            << std::setw(Task::MaxNameLenght+5) << task->name_
            << std::endl;
    }
    return out;
}