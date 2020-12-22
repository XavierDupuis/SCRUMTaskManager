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
    cout << " - - - BEGIN PROGRAM MAIN - - - " << endl;
    TaskManager taskManager = TaskManager(60, 3);
    Controller controller(taskManager);

    CSVHandler csvHandler("data.csv");
    csvHandler.readFile(taskManager);

    bool exit = false;
    while (!exit)
    {
        try 
        {
            exit = controller.menu();
        } 
        catch (InvalidInput& except)
        {
            cout << except.what() << endl;
        }
        catch (TaskNotFound& except)
        {
            cout << except.what() << endl;
        }
        catch (BadFileAccess& except)
        {
            cout << except.what() << endl;
            exit = true;
        }
    }
    csvHandler.writeFile(taskManager);

    cout << " - - - END PROGRAM MAIN - - - " << endl;
    
    return 0;
}