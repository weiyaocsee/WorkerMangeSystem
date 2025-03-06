#include <iostream>
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "worker.h"

int main()
{
    WorkerManager wm;

    // Worker * worker = NULL;
    // worker = new Employee(1, "张三", 1);
    // worker->showInfo();
    // delete worker;

    // worker = new Manager(1, "张四", 1);
    // worker->showInfo();
    // delete worker;

    // worker = new Boss(1, "张五", 1);
    // worker->showInfo();
    // delete worker;


    int choice = 0;

    while(true)
    {
        wm.showMenu();
        cout << "请输入您的选择：" << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
        wm.exitSystem();
            break;
        case 1:
        wm.addEmp();
            break;
        case 2:
        wm.show_Emp();
            break;
        case 3:
        wm.Delete_Emp();
            break;      
        case 4: 
        wm.Modify_Emp();
            break;
        case 5:
        wm.Find_Emp();
            break;
        case 6:
            break;
        case 7:
            break;     
        default:
        system("cls");
            break;
        }
    }
    
    
    
    return 0;
}