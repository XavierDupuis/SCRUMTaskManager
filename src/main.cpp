/**
 * @file main.cpp
 * @author XAVIER DUPUIS / OLIVIER SAINT-CYR
 * @e      xavier0978@hotmail.fr /  saintcyr.olivier1@gmail.com
 * @brief 
 * @version 0.1
 * @date 2020-12-12
 * 
 * @copyright Copyright (c) 2020
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <memory>

#include "Task.h"
#include "TaskManager.h"
#include "Controller.h"

using namespace std;

int main() {
    cout << " - - - BEGIN PROGRAM MAIN - - - " << endl;
    TaskManager taskManager = TaskManager(3, 60);
    Controller controller(taskManager);

    taskManager.AddTask(make_unique<Task>("taskUsefull", 12, 123));
    taskManager.AddTask(make_unique<Task>("taskUseless", 99, 666));
    taskManager.AddTask(make_unique<Task>("taskTrash", 35, 999));

    controller.inputAndAddTask();

    cout << taskManager << endl;

    try 
    {
        controller.removeTask();
    }
    catch (TaskNotFound& except) 
    {
        cout << except.what() << endl;
    }
    cout << taskManager << endl;

    cout << " - - - END PROGRAM MAIN - - - " << endl;
    
    return 0;
}