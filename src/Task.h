#ifndef TASK_H
#define TASK_H

#include <string>
#include <ostream>

struct Task
{
    Task(std::string name, unsigned weight, unsigned value);
    
    friend std::ostream& operator<<(std::ostream& out, const Task& task);

    std::string name;
    double netValue;
    unsigned weight;
    unsigned value;

private:
    void actualiseNetValue();
};

#endif
