#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
#include "worker.h"

WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    char ch;
    ifs >> ch;
    if(!ifs.is_open())
    {
        cout << "文件不存在！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        ifs.close();
        this->m_isFileEmpty = true;
        return;
    }

    else if(ifs.eof())
    {
        cout << "文件为空！" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        ifs.close();
        m_isFileEmpty = true;
        return;
    }
    else{
        this->m_isFileEmpty = false;
        this->m_EmpNum = this->get_EmpNum();
        cout << this->m_EmpNum << endl;
        this->m_EmpArray = new Worker*[this->m_EmpNum];
        this->init_Emp();
        for(int i = 0; i < m_EmpNum; i++)
        {
            cout << this->m_EmpArray[i]->m_Name << " ";
            cout << this->m_EmpArray[i]->m_ID << " ";
            cout << this->m_EmpArray[i]->m_DeptID << endl;
        }

    }

    

}

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int num = 0;
    int ID;
    string name;
    int dID;
    int index = 0;
    
    while(ifs >> ID && ifs >> name && ifs >> dID)
    {
        if(dID == 1)
        {
            Worker* worker = new Employee(ID, name, dID);
            this->m_EmpArray[index] = worker;
        }
        else if(dID == 2)
        {
            Worker* worker = new Manager(ID, name, dID);
            this->m_EmpArray[index] = worker;
        }
        else if(dID == 3)
        {
            Worker* worker = new Boss(ID, name, dID);
            this->m_EmpArray[index] = worker;
        }

        index++;
    }
    ifs.close();
}

int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);
    int num = 0;
    int ID;
    string name;
    int dID;
    
    while(ifs >> ID && ifs >> name && ifs >> dID)
    {
        num++;
    }

    ifs.close();

    return num;

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
        this->m_isFileEmpty = false;
        this->save();
    }
    else{
        cout << "输入有误" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::show_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->showInfo();
        }
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

int WorkerManager::m_isExist(int id)
{
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if(id == this->m_EmpArray[i]->m_ID)
        {
            return i;
        }
    }

    return -1;
}

// void WorkerManager::Delete_Emp()
// {
//     int del_id;
//     cout << "请输入要删除的用户ID:" << endl;
//     cin >> del_id;
//     for (int i = 0; i < this->m_EmpNum; i++)
//     {
//         if(del_id == this->m_EmpArray[i]->m_ID)
//         {
//             for (int j = i; j < this->m_EmpNum - 1; j++)
//             {
//                 this->m_EmpArray[j] = this->m_EmpArray[j+1];
//             }
//             this->m_EmpNum--;
//             this->save();
//             cout << "删除成功！" << endl;
//             system("pause");
//             system("cls");
//             return;
//         }
//     }
//     cout << "该用户不存在！" << endl;
//     system("pause");
//     system("cls");
//     return;
// }

void WorkerManager::Delete_Emp()
{
    int del_id;
    cout << "请输入要删除的用户ID:" << endl;
    cin >> del_id;
    int index = m_isExist(del_id);
    if(index != -1)
    {
            for (int j = index; j < this->m_EmpNum - 1; j++)
            {
                this->m_EmpArray[j] = this->m_EmpArray[j+1];
            }
            this->m_EmpNum--;
            this->save();
            cout << "删除成功！" << endl;
            system("pause");
            system("cls");
            return;
    }
    
    cout << "该用户不存在！" << endl;
    system("pause");
    system("cls");
    return;
}

void WorkerManager::Modify_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else{
        int mod_ID;
        int mod_index;
        cout << "请输入要修改的用户ID" << endl;
        cin >> mod_ID;
        mod_index = this->m_isExist(mod_ID);
        if(mod_index != -1)
        {
            int newID = 0;
            string newName = "";
            int newDeptID = 0;
            cout << "查到： " << mod_ID << "号职工，请输入新职工号： " << endl;
            cin >> newID;
            cout << "请输入新姓名： " << endl;
            cin >> newName;
            cout << "请输入岗位： " << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> newDeptID;
            delete this->m_EmpArray[mod_index];
            Worker*worker = NULL;
            switch (newDeptID)
            {
            case 1:
                m_EmpArray[mod_index] = new Employee(newID,newName,newDeptID);
                break;
            case 2:
                m_EmpArray[mod_index] = new Manager(newID,newName,newDeptID);
                break;
            case 3:
                m_EmpArray[mod_index] = new Boss(newID,newName,newDeptID);
                break;
            default:
                break;
            }

            cout << "修改成功！" << endl;
            this->save();

        }
        else
        {
            cout << "修改失败，查无此人！" << endl;
        }     
    }
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    cout << "请输入查找方式：" << endl;
    cout << "1.按职工编号查找" << endl;
    cout << "2.按姓名查找" << endl;

    int select;
    cin >> select;


    if(select == 1)
    {
        int id;
        cout << "请输入查找的用户编号：" << endl;
        cin >> id;
        int ret = this->m_isExist(id);
        if(ret == -1)
        {
            cout << "该用户不存在！" << endl;
        }
        else
        {
            cout << "查找成功，该用户信息如下：" << endl;
            this->m_EmpArray[ret]->showInfo();
        }

    }
    else if(select == 2)
    {
        string name;
        cout << "请输入查找的用户姓名：" << endl;
        cin >> name;

        bool find_Flag = false;
        for(int i = 0; i < this->m_EmpNum; i++)
        {
            if(name == this->m_EmpArray[i]->m_Name)
            {
                cout << "查找成功，该用户信息如下：" << endl;
                find_Flag = true;
                this->m_EmpArray[i]->showInfo();
            
            }
        }
        if(!find_Flag)
        {
            cout << "查找失败！" << endl;
        }

    }
    else
        cout << "输入有误！" << endl;

    system("pause");
    system("cls");
}

void WorkerManager::Sort_Emp()
{
    if (this->m_isFileEmpty)
    {
    cout << "文件不存在或记录为空！" << endl;
    system("pause");
    system("cls");
    }
    else
    {
        cout << "请选择排序方式： " << endl;
        cout << "1、按职工号进行升序" << endl;
        cout << "2、按职工号进行降序" << endl;
        int Sort_Sel = 0;
        cin >> Sort_Sel;



        if(Sort_Sel == 1)
        {
            for(int i = 0; i < this->m_EmpNum; i++)
            {
                int Min = i;
                for(int j = i + 1; j < this->m_EmpNum; j++)
                {
                    if(this->m_EmpArray[j]->m_ID < this->m_EmpArray[Min]->m_ID)
                    {
                        Min = j;
                        Worker * temp = this->m_EmpArray[i];
                        this->m_EmpArray[i] = this->m_EmpArray[j];
                        this->m_EmpArray[j] = temp;
                    }
                }
            }
        }
        else
        {
            for(int i = 0; i < this->m_EmpNum; i++)
            {
                int Max = i;
                for(int j = i + 1; j < this->m_EmpNum; j++)
                {
                    if(this->m_EmpArray[j]->m_ID > this->m_EmpArray[Max]->m_ID)
                    {
                        Max = j;
                        Worker * temp = this->m_EmpArray[i];
                        this->m_EmpArray[i] = this->m_EmpArray[j];
                        this->m_EmpArray[j] = temp;
                    }
                }
            }
        }
        this->save();
        this->show_Emp();
        system("pause");
        system("cls");
    }


}

void WorkerManager::Clean_File()
{
    cout << "确认清空？" << endl;
    cout << "1、确认" << endl;
    cout << "2、返回" << endl;

    int Cle_Sel = 0;
    cin >> Cle_Sel;

    if(Cle_Sel == 1)
    {
        ofstream ofs(FILENAME, ios::trunc);
        ofs.close();

        if(this->m_EmpArray != NULL)
        {
            for(int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArray[i];
            }
        }
        this->m_EmpNum = 0;
        delete[] this->m_EmpArray;
        this->m_EmpArray = NULL;
        this->m_isFileEmpty = true;
        cout << "清空成功！" << endl;
    }
    
    system("pause");
    system("cls");

}