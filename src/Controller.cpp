#include "Controller.h"

Controller::Controller(TaskManager& taskManager) 
    : taskManager_(taskManager)
{
}

void Controller::menu()
{
    std::cout << std::endl << std::endl << options_.second << std::endl;
    unsigned option = input<unsigned>("Option");
    if (option < 1 || option > options_.first)
    {
        InvalidInput("ERROR : Option not in range 1 to " + std::to_string(options_.first)).raise();
    }
    switch (option) 
    {
    case 1:
        taskManager_.displayTasks();
        break;
    case 2:
        inputAndAddTask();
        break;
    case 3:
        
        break;
    case 4:
        removeTask();
        break;
    default:
        std::cout << "Not an option" << std::endl;
        break;
    }
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
        TaskNotFound("ERROR : Task with id \"" + std::to_string(id) + "\" could not be found").raise();
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
        InvalidInput except("ERROR : Invalid Input for \"" + query + "\". Not of type <" + "..." + ">");
        except.raise();
    }
    return input;
}