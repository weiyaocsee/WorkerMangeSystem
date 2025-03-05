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
        this->save();
    }
    else{
        cout << "��������" << endl;
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