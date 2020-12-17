#include "Controller.h"

// Controller::Controller(){}

bool Controller::inputTask(TaskManager& taskManager)
{
    std::string name = inputValue<std::string>(" Task Name : ");
    unsigned value = inputValue<unsigned>(" Task Value : ");
    unsigned weight = inputValue<unsigned>(" Task weight : ");

    std::cout << std::endl;
    return taskManager.AddTask(std::make_unique<Task>(name,weight,value));
} 

template<typename T>
T Controller::inputValue(std::string query)
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