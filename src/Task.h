#ifndef TASK_H
#define TASK_H

#include <string>
#include <ostream>
#include <iomanip>

struct Task
{
    Task(std::string name, unsigned weight, unsigned value);
    
    friend std::ostream& operator<<(std::ostream& out, const Task& task);

    std::string name;
    double netValue;
    unsigned weight;
    unsigned value;
    unsigned id;

    static unsigned idCounter;

private:
    void actualiseNetValue();
};

#endif //TASK_H
