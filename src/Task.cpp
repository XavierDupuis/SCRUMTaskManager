#include "Task.h"
#include <limits>
#include <ostream>

Task::Task(std::string name, unsigned weight, unsigned value)
{
    this->name = name;
    this->weight = weight;
    this->value = value;
    actualiseNetValue();
}

std::ostream& operator<<(std::ostream& out, const Task& task)
{
    out << "Task " << task.name << " : weight = " << task.weight 
        << "  |  value =  " << task.value << std::endl;
    return out;
}


void Task::actualiseNetValue()
{
    if (weight == 0)
    {
        netValue = std::numeric_limits<double>::max();
    }
    else
    {
        netValue = double(value)/weight;
    }
}