#ifndef FILENOTFOUND_H
#define FILENOTFOUND_H

#include <stdexcept>

class FileNotFound : public std::runtime_error
{
public:
    FileNotFound(std::string what_arg = "")
    : std::runtime_error(what_arg) {} 

    virtual FileNotFound& raise() { throw *this; }
};

#endif // FILENOTFOUND_H
