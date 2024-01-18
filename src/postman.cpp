#include "../header/postman.h"

Postman::Postman(int id, const string &name, const string &username, const string &password, Department *department)
    : Person(id, name, username, password), department(department)
{
    // Will be implemented later...
}

void Postman::setDepartment(Department *newDepartment)
{
    int removeID = getId();
    department->employees.erase(
        remove_if(department->employees.begin(), department->employees.end(),
                  [removeID](const Postman *p)
                  {
                      return p->getId() == removeID;
                  }),
        department->employees.end());

    department = newDepartment;
    newDepartment->addPostman(this);
}

Department *Postman::getDepartment()
{
    return department;
}