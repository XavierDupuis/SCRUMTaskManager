#include "CSVHandler.h"

CSVHandler::CSVHandler(std::string filename = "data.csv") 
    : filename_(filename) 
{
}

bool CSVHandler::readFile(TaskManager& taskManager)
{
    std::ifstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " not found").raise();
    }
    std::string header;
    f >> header;
    f.ignore();

    std::vector<std::unique_ptr<Task>> tasks;
    
    //std::string stringId;
    std::string name;
    unsigned weight;
    unsigned value;
    
    Task::resetIdCounter();

    std::string ligne;
    while(std::getline(f,ligne)) 
    {
        std::istringstream stream(ligne);

        stream >> std::quoted(name);
        stream.ignore();
        stream >> weight;
        stream.ignore();
        stream >> value;
        stream.ignore(2);
        
        taskManager.AddTask(std::make_unique<Task>(name, weight, value));
    }


    f.close();
    return true;
}

bool CSVHandler::writeFile(TaskManager& taskManager)
{
    std::ofstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " couldn't be open.").raise();
    }
    f << "NAME;WEIGHT;VALUE;\n";
    for(auto& it : taskManager.getTasks())
    {
        f << 
     "\"" << it.get()->name << "\"" << ";" << 
             it.get()->weight << ";" << 
             it.get()->value << ";" << std::endl;
    }
    f.close();
    return true;
}