#ifndef TASKNOTFOUND_H
#define TASKNOTFOUND_H

#include <stdexcept>

class TaskNotFound : public std::logic_error 
{
public:
    TaskNotFound(std::string what_arg = "")
    : std::logic_error(what_arg) {} 

    virtual TaskNotFound& raise() { throw *this; }
};

#endif // TASKNOTFOUND_H
