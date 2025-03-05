#pragma once
#include <iostream>
#include "worker.h"
#include <string>

using namespace std;

class Manager:public Worker
{
public:
    Manager(int ID, string Name, int dId);
    virtual void showInfo();
    virtual string getDeptName();

};