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
#include "CSVHandler.h"

using namespace std;

int main() 
{
    // - - - BEGIN PROGRAM MAIN - - - 
    TaskManager taskManager = TaskManager(60, 3);
    Controller controller(taskManager);
    controller.routine();
    // - - - END PROGRAM MAIN - - - 
    return 0;
}