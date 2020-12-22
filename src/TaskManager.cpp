#include "TaskManager.h"

TaskManager::TaskManager(unsigned iterationWeight, unsigned iterationPeriod)
    : iterationWeight_(iterationWeight), iterationPeriod_(iterationPeriod)
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
        return task->id_ == id;
    });
    
    if (pos != tasks_.end())
    {
        (*pos)->weight_ = weight;
        (*pos)->value_ = value;
        return true;
    }
    return false;
}

std::vector<std::unique_ptr<Task>>& TaskManager::getTasks()
{
    return tasks_;
}

bool TaskManager::RemoveTask(const unsigned long& id)
{
    auto pos = std::find_if(tasks_.begin(), tasks_.end(), [&id](std::unique_ptr<Task>& task)
    {
        return task->id_ == id;
    });
    
    if (pos != tasks_.end())
    {
        tasks_.erase(remove(tasks_.begin(), tasks_.end(), *pos));
        return true;
    }
    return false;
}

std::ostream& operator<<(std::ostream& out, const TaskManager& taskManager)
{
    if (taskManager.tasks_.size() == 0)
    {
        out << "No tasks in TaskManager." << std::endl;
        return out;
    }
    out << " TaskManager Tasks : " << std::endl;
    out << std::left
              << std::setw(5) << "ID" 
              << std::setw(Task::MaxNameLenght+2) << "NAME" 
              << std::setw(10) << "WEIGHT"
              << std::setw(10) << "VALUE"
              << std::setw(10) << "RATIO (W/V)" << std::endl;
    for (auto& it : taskManager.tasks_)
    {
        out << *it << std::endl;
    }
    return out;
}

void TaskManager::displayTasks()
{
    std::cout << *this;
}

void TaskManager::displayTimeTable()
{
    if (tasks_.size() == 0)
    {
        std::cout << "No tasks in TaskManager." << std::endl;
        return;
    }
    std::cout << " Time Table : " << std::endl;
    for (auto& iteration : timeTable_)
    {
        std::cout << *iteration << std::endl;
    }
}

void TaskManager::createTimeTable()
{
    sortTasks();
    timeTable_.clear();
    tasksTooHeavy_.clear();

    std::vector<const Task*> tasksToPlace = orderedTasksByRatio_;

    while (tasksToPlace.size() != 0)
    {
        std::unique_ptr<Iteration> iteration = std::make_unique<Iteration>();
        for (auto it = tasksToPlace.begin(); it != tasksToPlace.end(); it++)
        {
            if ((*it)->weight_ > iterationWeight_)
            {
                tasksTooHeavy_.push_back(*it);
                tasksToPlace.erase(it);
                it--;
            }
            else if ((*it)->weight_ + iteration->totalWeight <= iterationWeight_)
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
    orderedTasksByRatio_.clear();
    auto funcUniqueToPtr = [](const std::unique_ptr<Task>& taskptr) {return taskptr.get();};
    
    transform(tasks_.begin(), tasks_.end(), back_inserter(orderedTasksByRatio_), funcUniqueToPtr);

	std::sort(orderedTasksByRatio_.begin(), orderedTasksByRatio_.end(), 
    [](const Task* task1,const Task* task2)
	{
		return task1->ratioWV_ > task2->ratioWV_;
	});
}
