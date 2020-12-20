#include "TaskManager.h"

TaskManager::TaskManager(unsigned iterPeriod, unsigned maxEffortByPeriod)
    : iterPeriod_(iterPeriod), maxEffortByPeriod_(maxEffortByPeriod)
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

void TaskManager::sortTasks()
{
	std::sort(tasks_.begin(), tasks_.end(), [](const std::unique_ptr<Task>& task1,
						   const std::unique_ptr<Task>& task2)
	{
		return task1->netValue < task2->netValue;
	});
}
