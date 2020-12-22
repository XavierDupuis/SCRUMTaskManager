#include "Task.h"
#include <limits>
#include <ostream>

unsigned Task::idCounter = 0;

size_t Task::MaxNameLenght = 4;

Task::Task(std::string name, unsigned weight, unsigned value) : 
    name_(name), 
    weight_(weight),
    value_(value),
    id_(idCounter++)
{
    actualiseNetValue();
    Task::setMaxNameLenght(std::max(MaxNameLenght, name.size()));
}

std::ostream& operator<<(std::ostream& out, const Task& task)
{
    out << std::left 
        << std::setw(5) << task.id_ 
        << std::setw(Task::MaxNameLenght+2) << task.name_ 
        << std::setw(10) << task.weight_ 
        << std::setw(10) << task.value_
        << std::setw(10) << task.ratioWV_;
    return out;
}

void Task::actualiseNetValue()
{
    if (weight_ == 0)
    {
        ratioWV_ = std::numeric_limits<double>::max();
    }
    else
    {
        ratioWV_ = double(value_)/weight_;
    }
}

void Task::setIdCounter(unsigned newID)
{
    idCounter = newID;
}

void Task::resetIdCounter()
{
    setIdCounter(0);
}

void Task::setMaxNameLenght(size_t newMaxNameLenght)
{
    MaxNameLenght = newMaxNameLenght;
}