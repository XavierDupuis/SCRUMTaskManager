#include "TaskManager.h"

using namespace std;

TaskManager::TaskManager(unsigned iterPeriod, unsigned maxEffortByPeriod)
    : iterationWeight_(iterPeriod), maxEffortByPeriod_(maxEffortByPeriod)
{
}

bool TaskManager::AddTask(std::unique_ptr<Task> task)
{
    if (task != nullptr)
    {
        tasks_.push_back(std::move(task));
        return true;
    }
    return false;
}

bool TaskManager::UpdateTask(unsigned long& id, unsigned weight, unsigned value)
{
    auto pos = std::find_if(tasks_.begin(), tasks_.end(), [&id](std::unique_ptr<Task>& task)
    {
        return task->id == id;
    });
    
    if (pos != tasks_.end())
    {
        (*pos)->weight = weight;
        (*pos)->value = value;
        return true;
    }
    return false;
}

//std::vector<const Task*>
std::vector<std::unique_ptr<Task>>& TaskManager::getTasks()
{
    return tasks_;
}

bool TaskManager::RemoveTask(const unsigned long& id)
{
    auto pos = std::find_if(tasks_.begin(), tasks_.end(), [&id](std::unique_ptr<Task>& task)
    {
        return task->id == id;
    });
    
    if (pos != tasks_.end())
    {
        /*std::iter_swap(pos, tasks_.end()-1);
        tasks_.pop_back();*/
        tasks_.erase(remove(tasks_.begin(), tasks_.end(), *pos));
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const TaskManager& taskManager)
{
    out << " TaskManager Tasks : " << std::endl;
    for (auto& it : taskManager.tasks_)
    {
        out << *it << std::endl;
    }
    return out;
}

void TaskManager::displayTasks()
{
    std::cout << " TaskManager Tasks : " << std::endl;
    for (auto& it : tasks_)
    {
        std::cout << *it << std::endl;
    }
}

void TaskManager::displayTimeTable()
{
    std::cout << " TaskManager Tasks : " << std::endl;
    for (auto& iteration : timeTable_)
    {
        std::cout << *iteration << std::endl;
    }
}

void TaskManager::createTimeTable()
{
    timeTable_.clear();

    vector<const Task*> tasksToPlace;
    auto funcUniqueToPtr = [](const unique_ptr<Task>& taskptr) {return taskptr.get();};
    
    sortTasks();
    transform(tasks_.begin(), 
              tasks_.end(), 
              back_inserter(tasksToPlace), 
              funcUniqueToPtr);

    while (tasksToPlace.size() != 0)
    {
        unique_ptr<Iteration> iteration = make_unique<Iteration>();
        for (auto it = tasksToPlace.begin(); it != tasksToPlace.end(); it++)
        {
            if ((*it)->weight > iterationWeight_)
            {
                tasksToPlace.erase(it);
                it--;
            }
            
            if ((*it)->weight + iteration->totalWeight <= iterationWeight_)
            {
                iteration->addTask(*it);
                tasksToPlace.erase(it);
                it--;
            }
        }
        timeTable_.push_back(move(iteration));
    }
}

void TaskManager::sortTasks()
{
	std::sort(tasks_.begin(), tasks_.end(), [](const std::unique_ptr<Task>& task1,
						   const std::unique_ptr<Task>& task2)
	{
		return task1->netValue > task2->netValue;
	});
}
