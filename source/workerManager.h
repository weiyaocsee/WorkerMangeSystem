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

    bool m_isFileEmpty;

    int get_EmpNum();

    void init_Emp();

    void show_Emp();

    void Delete_Emp();

    int m_isExist(int id);

    void Modify_Emp();

    void Find_Emp();
};





