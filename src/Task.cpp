#include "Task.h"
#include <limits>

Task::Task(std::string name, unsigned weight, unsigned value)
{
    this->name = name;
    this->weight = weight;
    this->value = value;
    actualiseNetValue();
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