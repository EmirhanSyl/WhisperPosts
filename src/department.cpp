#include "../header/Department.h"
#include "../header/database.h"

Department::Department(int initID, string initName, Address initAddress, DepartmentType initType)
    : id(initID), name(initName), address(initAddress), type(initType)
{
    Database::departments.push_back(this);
}

Department::~Department() {}

unordered_map<DepartmentType, string> Department::department_type_names = {
    {post_office, "POST OFFICE"},
    {transfer_center, "TRANSFER CENTER"}};

int Department::getId() const
{
    return id;
}

void Department::setId(int newId)
{
    id = newId;
}

string Department::getName() const
{
    return name;
}

void Department::setName(const string newName)
{
    name = newName;
}

Address Department::getAddress() const
{
    return address;
}

void Department::setAddress(Address newAddress)
{
    //address = newAddress;
}

DepartmentType Department::getType() const
{
    return type;
}

void Department::setType(DepartmentType newType)
{
    type = newType;
}

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