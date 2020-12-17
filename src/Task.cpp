#include "Task.h"
#include <limits>
#include <ostream>

unsigned Task::idCounter = 0;

Task::Task(std::string name, unsigned weight, unsigned value)
{
    this->name = name;
    this->weight = weight;
    this->value = value;
    this->id = idCounter++;
    actualiseNetValue();
}

std::ostream& operator<<(std::ostream& out, const Task& task)
{
    //sprintf();
    
    out << "id : " << task.id << std::setw(15) << task.name << " : weight = " << task.weight 
        << "  |  value =  " << task.value;
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