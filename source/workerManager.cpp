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
        cout << "�ļ������ڣ�" << endl;
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        ifs.close();
        this->m_isFileEmpty = true;
        return;
    }

    else if(ifs.eof())
    {
        cout << "�ļ�Ϊ�գ�" << endl;
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
    cout << "********* ��ӭʹ��ְ������ϵͳ�� **********" << endl;
    cout << "************* 0.�˳�������� *************" << endl;
    cout << "************* 1.����ְ����Ϣ *************" << endl;
    cout << "************* 2.��ʾְ����Ϣ *************" << endl;
    cout << "************* 3.ɾ����ְְ�� *************" << endl;
    cout << "************* 4.�޸�ְ����Ϣ *************" << endl;
    cout << "************* 5.����ְ����Ϣ *************" << endl;
    cout << "************* 6.���ձ������ *************" << endl;
    cout << "************* 7.��������ĵ� *************" << endl;
    cout << "********************************************" << endl;
    cout << endl;
}

void WorkerManager::exitSystem()
{
    cout <<"��ӭ�´�ʹ�ã�" << endl;
    system("pause");
    exit(0);
}

void WorkerManager::addEmp()
{   
    cout << "��������ӵ�Ա��������" << endl;
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

            cout << "�������" << i+1 << "����ְ���ı�ţ�" << endl;
            cin >> id;

            cout << "�������" << i+1 << "����ְ����������" << endl;
            cin >> name;

            cout << "��ѡ���ְ���ĸ�λ��" << endl;
            cout << "1.��ְͨ��" << endl;
            cout << "2.����" << endl;
            cout << "3.�ϰ�" << endl;
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
        this->m_EmpArray = newspace;  //ϸ��
        this->m_EmpNum = newsize;

        cout << "�ɹ����" << addNum << "����ְ��"<< endl;
        this->m_isFileEmpty = false;
        this->save();
    }
    else{
        cout << "��������" << endl;
    }
    system("pause");
    system("cls");
}

void WorkerManager::show_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
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

    cout << "�ɹ�д���ļ���" << endl;

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
//     cout << "������Ҫɾ�����û�ID:" << endl;
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
//             cout << "ɾ���ɹ���" << endl;
//             system("pause");
//             system("cls");
//             return;
//         }
//     }
//     cout << "���û������ڣ�" << endl;
//     system("pause");
//     system("cls");
//     return;
// }

void WorkerManager::Delete_Emp()
{
    int del_id;
    cout << "������Ҫɾ�����û�ID:" << endl;
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
            cout << "ɾ���ɹ���" << endl;
            system("pause");
            system("cls");
            return;
    }
    
    cout << "���û������ڣ�" << endl;
    system("pause");
    system("cls");
    return;
}

void WorkerManager::Modify_Emp()
{
    if(this->m_isFileEmpty)
    {
        cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    }
    else{
        int mod_ID;
        int mod_index;
        cout << "������Ҫ�޸ĵ��û�ID" << endl;
        cin >> mod_ID;
        mod_index = this->m_isExist(mod_ID);
        if(mod_index != -1)
        {
            int newID = 0;
            string newName = "";
            int newDeptID = 0;
            cout << "�鵽�� " << mod_ID << "��ְ������������ְ���ţ� " << endl;
            cin >> newID;
            cout << "�������������� " << endl;
            cin >> newName;
            cout << "�������λ�� " << endl;
            cout << "1����ְͨ��" << endl;
            cout << "2������" << endl;
            cout << "3���ϰ�" << endl;
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

            cout << "�޸ĳɹ���" << endl;
            this->save();

        }
        else
        {
            cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
        }     
    }
    system("pause");
    system("cls");
}

void WorkerManager::Find_Emp()
{
    cout << "��������ҷ�ʽ��" << endl;
    cout << "1.��ְ����Ų���" << endl;
    cout << "2.����������" << endl;

    int select;
    cin >> select;


    if(select == 1)
    {
        int id;
        cout << "��������ҵ��û���ţ�" << endl;
        cin >> id;
        int ret = this->m_isExist(id);
        if(ret == -1)
        {
            cout << "���û������ڣ�" << endl;
        }
        else
        {
            cout << "���ҳɹ������û���Ϣ���£�" << endl;
            this->m_EmpArray[ret]->showInfo();
        }

    }
    else if(select == 2)
    {
        string name;
        cout << "��������ҵ��û�������" << endl;
        cin >> name;

        bool find_Flag = false;
        for(int i = 0; i < this->m_EmpNum; i++)
        {
            if(name == this->m_EmpArray[i]->m_Name)
            {
                cout << "���ҳɹ������û���Ϣ���£�" << endl;
                find_Flag = true;
                this->m_EmpArray[i]->showInfo();
            
            }
        }
        if(!find_Flag)
        {
            cout << "����ʧ�ܣ�" << endl;
        }

    }
    else
        cout << "��������" << endl;

    system("pause");
    system("cls");
}

void WorkerManager::Sort_Emp()
{
    if (this->m_isFileEmpty)
    {
    cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
    system("pause");
    system("cls");
    }
    else
    {
        cout << "��ѡ������ʽ�� " << endl;
        cout << "1����ְ���Ž�������" << endl;
        cout << "2����ְ���Ž��н���" << endl;
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
    cout << "ȷ����գ�" << endl;
    cout << "1��ȷ��" << endl;
    cout << "2������" << endl;

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
        cout << "��ճɹ���" << endl;
    }
    
    system("pause");
    system("cls");

}