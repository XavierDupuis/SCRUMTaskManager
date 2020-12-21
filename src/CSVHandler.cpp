#include "CSVHandler.h"

CSVHandler::CSVHandler(std::string filename = "data.csv") 
    : filename_(filename) 
{};

bool CSVHandler::readFile(TaskManager& taskManager)
{
    std::ifstream f(filename_);
    if(!f)
    {
        FileNotFound("File" + filename_ + "not found").raise();
    }
    std::string header;
    f >> header;

    std::vector<std::unique_ptr<Task>> tasks;
    
    //std::string stringId;
    std::string stringName;
    std::string stringWeight;
    std::string stringValue;
    
    Task::resetIdCounter();

    while(f.peek() != EOF) 
    {
        //getline(f,stringId,';');
        getline(f,stringName,';');
        getline(f,stringWeight,';');
        getline(f,stringValue,';');
        taskManager.AddTask(std::make_unique<Task>(stringName, stoul(stringWeight), stoul(stringValue)));
    }
    
    f.close();
    return true;
}

bool CSVHandler::writeFile(TaskManager& taskManager)
{
    std::ofstream f(filename_);
    f << "ID;NAME;WEIGHT;VALUE" << std::endl;
    for(auto& it : taskManager.getTasks())
    {
        f << 
             //it->id << ";" << 
             it.get()->name << ";" << 
             it.get()->value << ";" << 
             it.get()->weight << std::endl;

    }
    f.close();
    return true;
}