/**
 * @file main.cpp
 * @author XAVIER DUPUIS (xavier0978@hotmail.fr)
 * @brief 
 * @version 0.1
 * @date 2020-12-12
 * 
 * @copyright Copyright (c) 2020
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

#include "t1.h"
#include "t2.h"

using namespace std;

int main() {
    cout << "TEST PROGRAM MAIN" << endl;
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