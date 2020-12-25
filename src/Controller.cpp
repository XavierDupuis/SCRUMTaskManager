#include "Controller.h"

Controller::Controller(TaskManager& taskManager) 
    : taskManager_(taskManager)
{
}

void Controller::routine()
{
    CSVHandler csvHandler("data.csv");

    try
    {
        csvHandler.readFile(taskManager_);
    } 
    catch (BadFileAccess& except)
    {
        std::cout << except.what() << std::endl;
        std::cout << "'data.csv' will be created" << std::endl;
        std::cout << "Close and restart program" << std::endl;
        csvHandler.writeFile(taskManager_);
        return;
    }

    bool exit = false;
    while (!exit)
    {
        try 
        {
            exit = menu();
        } 
        catch (InvalidInput& except)
        {
            std::cout << except.what() << std::endl;
        }
        catch (TaskNotFound& except)
        {
            std::cout << except.what() << std::endl;
        }
        catch (BadFileAccess& except)
        {
            std::cout << except.what() << std::endl;
            exit = true;
        }
    }
    csvHandler.writeFile(taskManager_);
}

bool Controller::menu()
{
    std::cout << std::endl << std::endl << options_.second << std::endl;
    unsigned option = input<unsigned>("Option");
    std::cout << std::endl;
    if (option > options_.first-1)
    {
        InvalidInput("ERROR : Option not in range 0 to " + std::to_string(options_.first-1)).raise();
    }
    bool exit = false;
    switch (option) 
    {
    case 1:
        taskManager_.displayTasks();
        break;
    case 2:
        taskManager_.addTask(inputTask());
        break;
    case 3:
        taskManager_.updateTask(inputTask());
        break;
    case 4:
        removeTask();
        break;
    case 5:
        taskManager_.createTimeTable();
        taskManager_.displayTimeTable();
        break;
    case 0:
    default:
        std::cout << "Exit" << std::endl;
        exit = true;
        break;
    }
    return exit;
}

std::unique_ptr<Task> Controller::inputTask()
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
    return std::make_unique<Task>(name,weight,value);
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

    if (!taskManager_.removeTask(id)) 
    {
        TaskNotFound("ERROR : Task with id \"" + std::to_string(id) + "\" could not be found").raise();
    }
    std::cout << "Task with id \"" << id << "\" deleted" << std::endl;
    return true;
}

bool updateTask()
{
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
        InvalidInput except("ERROR : Invalid Input for \"" + query + "\". Not of type <" + typeid(T).name() + ">");
        except.raise();
    }
    return input;
}