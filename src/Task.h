#ifndef TASK_H
#define TASK_H

#include <string>

struct Task
{
    Task(std::string name, unsigned weight, unsigned value);
    
    std::string name;
    double netValue;
    unsigned weight;
    unsigned value;

private:
    void actualiseNetValue();
};

#endif