#ifndef POSTMAN_H
#define POSTMAN_H

#include "person.h"
#include "department.h"

class Department;
class Postman : public Person
{
private:
    Department *department;
public:
    Postman(int id, const string &name, const string &username, const string &password, Department *department);
    Postman();
    ~Postman();

    void setDepartment(Department *newDepartment);
    Department *getDepartment();
};

#endif