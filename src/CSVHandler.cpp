#include "CSVHandler.h"

CSVHandler::CSVHandler(std::string filename = "data.csv") 
    : filename_(filename) 
{
}

bool CSVHandler::readFile(TaskManager& taskManager)
{
    // Open file
    std::ifstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " not found").raise();
    }
    std::string header;

    // Remove header
    f >> header;
    f.ignore();
    
    // Reset ID Counter
    Task::resetIdCounter();

    //Local Variables
    std::string name;
    unsigned weight;
    unsigned value;
    std::string ligne;

    //Get each line from .csv
    while(std::getline(f,ligne)) 
    {
        std::istringstream stream(ligne);
        getline(stream, name, ';');
        stream >> weight;
        stream.ignore();
        stream >> value;
        stream.ignore();
        taskManager.addTask(std::make_unique<Task>(name, weight, value));
    }
    f.close();
    return true;
}

bool CSVHandler::writeFile(TaskManager& taskManager)
{
    std::ofstream f(filename_);
    if(!f)
    {
        BadFileAccess("File " + filename_ + " couldn't be overwritten.").raise();
    }
    f << "NAME;WEIGHT;VALUE\n";
    for(auto& it : taskManager.getTasks())
    {
        f << it.get()->name_     << ";" << 
             it.get()->weight_   << ";" << 
             it.get()->value_    << std::endl;
    }
    f.close();
    return true;
}