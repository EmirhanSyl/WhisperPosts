#include "../header/Department.h"
#include "../header/database.h"

Department::Department(int initID, string initName, Address initAddress, DepartmentType initType)
    : id(initID), name(initName), address(initAddress), type(initType)
{
    Database::departments.push_back(this);
}

Department::~Department() {}

void Department::addPostman(Postman *postman)
{
    employees.push_back(postman);
}

Postman *Department::getPostman(int index)
{
    if (index >= 0 && index < employees.size())
    {
        return employees[index];
    }
    return nullptr; // Index out of bounds
}