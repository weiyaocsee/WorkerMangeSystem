#include "manager.h"

Manager::Manager(int ID, string name, int dId)
{
    this->m_ID = ID;
    this->m_Name = name;
    this->m_DeptID = dId;  
}

void Manager::showInfo()
{
    cout << "ְ����ţ�" << this->m_ID
    << " \tְ��������" << this->m_Name
    << " \t��λ��" << this->getDeptName()
    << " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

string Manager::getDeptName()
{
    return string("����");
}