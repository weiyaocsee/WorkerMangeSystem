#pragma once
#include <iostream>

using namespace std;
#include "worker.h"

class Boss : public Worker
{
public:
    Boss(int ID, string name, int dID);

    void showInfo();
    string getDeptName();

};