#include "employee.h"
#include "string"

Employee::Employee(int ID, string name, int dID)
{
    this->m_ID = ID;
    this->m_Name = name;
    this->m_DeptID = dID;
}

void Employee::showInfo()
{
    cout << "ְ����ţ�" << this->m_ID
    << "\tְ��������" << this->m_Name
    << "\t��λ��" << this->getDeptName()
    << "\t��λְ����ɾ�����������" << endl;
}

string Employee::getDeptName()
{
    return string("��ͨԱ��");
}