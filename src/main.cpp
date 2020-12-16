/**
 * @file main.cpp
 * @author XAVIER DUPUIS, OLIVIER SAINT-CYR (xavier0978@hotmail.fr)
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
    cout << "TEST PROGRAM MAIN" << endl;
    TaskManager taskManager = TaskManager();

    unique_ptr<Task> task1 = std::make_unique<Task>("Do dishes", 987, 654);
    taskManager.tasks_.push_back(move(task1));

    cout << "Task 0 : weight = " << taskManager.tasks_[0]->weight 
       << "  |  value =  " << taskManager.tasks_[0]->value << endl;

    cout << T2().t2content << endl;
    string name;
    while (true)
    {
        cout << " ENTER YOUR NAME : ";
        cin >> name;
        cout << endl;
        cout << " HELLO " << name;
        cout << endl << endl;
    }
}