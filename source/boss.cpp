#include "boss.h"
#include "string"

Boss::Boss(int ID, string name, int dID)
{
    this->m_ID = ID;
    this->m_Name = name;
    this->m_DeptID = dID;
}

void Boss::showInfo()
{
    cout << "ְ����ţ�" << this->m_ID
    << "\tְ��������" << this->m_Name
    << "\t��λ��" << this->getDeptName()
    << "\t��λְ�𣺹���˾��������" << endl;
}

string Boss::getDeptName()
{
    return string("�ϰ�");
}