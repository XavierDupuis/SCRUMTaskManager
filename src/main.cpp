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

#include "TaskManager.h"
#include "t2.h"

using namespace std;

int main() {
    cout << " - - - BEGIN PROGRAM MAIN - - - " << endl;
    TaskManager taskManager = TaskManager();

    unique_ptr<Task> task1 = make_unique<Task>("Do dishes", 987, 654);
    taskManager.tasks_.push_back(move(task1));

    // cout << "Task 0 : weight = " << taskManager.tasks_[0]->weight 
    //    << "  |  value =  " << taskManager.tasks_[0]->value << endl;
    
    cout << *taskManager.tasks_[0];

    cout << T2().t2content << endl;
    string name;

    
    cout << " - - - END PROGRAM MAIN - - - " << endl;
    // Next 2 lines are for single window behavior
    cout << " - - - CTRL+C TO ABORT - - - " << endl;
    while (true) {}

    return 0;
}