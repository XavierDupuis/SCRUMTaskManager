#include "Controller.h"

Controller::Controller(TaskManager& taskManager) 
    : taskManager_(taskManager)
{
}

bool Controller::inputAndAddTask()
{
    std::string name;
    unsigned value;
    unsigned weight;
    bool valid = false;
    while (!valid) 
    {
        try
        {
            name = input<std::string>("Task Name");
            value = input<unsigned>("Task Value");
            weight = input<unsigned>("Task Weight");
            valid = true;
        }
        catch (InvalidInput& except)
        {
            std::cout << except.what() << std::endl;
        }
    }
    std::cout << std::endl;
    return taskManager_.AddTask(std::make_unique<Task>(name,weight,value));
} 

bool Controller::removeTask()
{
    unsigned long id;
    bool valid = false;

    while (!valid) 
    {
        try
        {
            id = input<unsigned long>("Task ID");
            valid = true;
        }
        catch (InvalidInput& except)
        {
            std::cout << except.what() << std::endl;
        }
    }

    if (!taskManager_.RemoveTask(id)) 
    {
        TaskNotFound except("ERROR : Task with id \"" + std::to_string(id) + "\" could not be found");
        except.raise();
    }
    std::cout << "Task with id \"" << id << "\" deleted" << std::endl;
    return true;
}

template<typename T>
T Controller::input(std::string query)
{
    T input;
    std::cout << query << " : " << std::endl << "> ";
    std::cin >> input;
    if (std::cin.fail()) 
    {
        std::cin.clear();
        std::cin.ignore(80,'\n');
        InvalidInput except("ERROR : Invalid Input for \"" + query + "\"");
        except.raise();
    }
    return input;
}