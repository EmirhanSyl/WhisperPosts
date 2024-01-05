#include "../header/postman.h"

Postman::Postman(int id, const string &name, const string &username, const string &password, const string &mail, Department *department)
    : Person(id, name, username, password, mail), department(department)
{
    // Will be implemented later...
}

Postman::~Postman() {}

void Postman::setDepartment(Department *newDepartment){
    department = newDepartment;
}

Department *Postman::getDepartment(){
    return department;
}