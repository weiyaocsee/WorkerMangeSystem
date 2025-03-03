#include <iostream>
#include "workerManager.h"
#include "employee.h"
#include "worker.h"

int main()
{
    WorkerManager wm;
    Worker * worker = NULL;
    worker = new Employee(1, "张三", 1);
    worker->showInfo();


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
            break;
        case 2:
            break;
        case 3:
            break;      
        case 4:
            break;
        case 5:
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