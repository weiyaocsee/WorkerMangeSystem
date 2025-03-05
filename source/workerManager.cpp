#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "worker.h"

WorkerManager::WorkerManager()
{
    this->m_EmpNum = 0;
    this->m_EmpArray = NULL;
}

WorkerManager::~WorkerManager()
{

}

void WorkerManager::showMenu()
{
    cout << "********************************************" << endl;
    cout << "********* 欢迎使用职工管理系统！ **********" << endl;
    cout << "************* 0.退出管理程序 *************" << endl;
    cout << "************* 1.增加职工信息 *************" << endl;
    cout << "************* 2.显示职工信息 *************" << endl;
    cout << "************* 3.删除离职职工 *************" << endl;
    cout << "************* 4.修改职工信息 *************" << endl;
    cout << "************* 5.查找职工信息 *************" << endl;
    cout << "************* 6.按照编号排序 *************" << endl;
    cout << "************* 7.清空所有文档 *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout <<"欢迎下次使用！" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::addEmp()
{   
    cout << "请输入添加的员工数量：" << endl;
    int addNum;
    cin >> addNum;

    if(addNum > 0)
    {
        int newsize = addNum + this->m_EmpNum;
        Worker** newspace = new Worker*[newsize];

        if(this->m_EmpArray != NULL)
        {
            for(int i = 0; i < this->m_EmpNum; i++)
            {
                newspace[i] = this->m_EmpArray[i];
            }
        }

        for(int i = 0; i < addNum; i++)
        {
            int id;
            string name;
            int dID;

            cout << "请输入第" << i+1 << "个新职工的编号：" << endl;
            cin >> id;

            cout << "请输入第" << i+1 << "个新职工的姓名：" << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1.普通职工" << endl;
            cout << "2.经理" << endl;
            cout << "3.老板" << endl;
            cin >> dID;

            Worker * worker = NULL;
            switch (dID)
            {
            case 1:
                worker = new Employee(id, name, dID);
                break;
            case 2:
                worker = new Manager(id, name, dID);
                break;
            case 3:
                worker = new Boss(id, name, dID);
                break;
            default:
                break;
            }

            newspace[this->m_EmpNum + i] = worker;
            
        }

        delete[] this->m_EmpArray;
        this->m_EmpArray = newspace;  //细看
        this->m_EmpNum = newsize;

        cout << "成功添加" << addNum << "名新职工"<< endl;
        this->save();
    }
    else{
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out);

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_ID << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptID << endl;
    }

    cout << "成功写入文件！" << endl;

    ofs.close();

}