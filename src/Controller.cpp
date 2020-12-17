#include "Controller.h"

Controller::Controller(TaskManager& taskManager) 
    : taskManager_(taskManager)
{
}

bool Controller::inputAndAddTask()
{
    std::string name = input<std::string>(" Task Name : ");
    unsigned value = input<unsigned>(" Task Value : ");
    unsigned weight = input<unsigned>(" Task weight : ");

    std::cout << std::endl;
    return taskManager_.AddTask(std::make_unique<Task>(name,weight,value));
} 

bool Controller::removeTask()
{
    return taskManager_.RemoveTask(input<unsigned long>(" Task ID : "));
}

template<typename T>
T Controller::input(std::string query)
{
    bool validInput = true;
    T input;
    do 
    {
        std::cout << query;
        std::cin >> input;
        if (std::cin.fail()) 
        {
            validInput = false;
            std::cout << "     Invalid Input     " << std::endl;
            std::cin.clear();
            std::cin.ignore(80,'\n');
        }
        else
        {
            validInput = true;
        }
    } while (!validInput);
    return input;
}