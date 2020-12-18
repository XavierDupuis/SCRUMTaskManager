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

#include "../src/Task.h"
#include "../src/TaskManager.h"
#include "../src/Controller.h"

using namespace std;

int main() {
    cout << " - - - BEGIN TEST MAIN - - - " << endl;
    TaskManager taskManager = TaskManager(3, 60);
    Controller controller(taskManager);

    taskManager.AddTask(make_unique<Task>("taskTest1", 12, 123));
    taskManager.AddTask(make_unique<Task>("taskTest2", 99, 666));
    taskManager.AddTask(make_unique<Task>("taskTest3", 35, 999));

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

    cout << " - - - END TEST MAIN - - - " << endl;
    
    return 0;
}