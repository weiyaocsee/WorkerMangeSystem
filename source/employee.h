#pragma once
#include <iostream>

using namespace std;
#include "worker.h"

class Employee : public Worker
{
public:
    Employee(int ID, string name, int dID);

    void showInfo();
    string getDeptName();


};