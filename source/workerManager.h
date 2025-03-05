#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "worker.h"

#define FILENAME "empFile.txt"


using namespace std;

class WorkerManager
{
public:
    WorkerManager();

    void showMenu();

    ~WorkerManager();

    void exitSystem();

    void addEmp();

    void save();

    int m_EmpNum;
    
    Worker **m_EmpArray;
};





