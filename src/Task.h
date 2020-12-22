#ifndef TASK_H
#define TASK_H

#include <string>
#include <ostream>
#include <iomanip>
#include <algorithm>

struct Task
{
    Task(std::string name, unsigned weight, unsigned value);
    
    friend std::ostream& operator<<(std::ostream& out, const Task& task);

    std::string name_;
    double ratioWV_;
    unsigned weight_;
    unsigned value_;
    unsigned id_;

    static unsigned idCounter;
    static void setIdCounter(unsigned newID);
    static void resetIdCounter();

    static size_t MaxNameLenght;
    static void setMaxNameLenght(size_t newMaxNameLenght);

private:
    void actualiseNetValue();
};

#endif //TASK_H
