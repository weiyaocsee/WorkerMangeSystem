#include "employee.h"
#include "string"

Employee::Employee(int ID, string name, int dID)
{
    this->m_ID = ID;
    this->m_name = name;
    this->m_DeptID = dID;
}

void Employee::showInfo()
{
    cout << "职工编号：" << this->m_ID
    << "\t职工姓名：" << this->m_name
    << "\t岗位：" << this->getDeptName()
    << "\t岗位职责：完成经理交给的任务" << endl;
}

string Employee::getDeptName()
{
    return string("普通员工");
}