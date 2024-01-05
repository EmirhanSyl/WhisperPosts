#ifndef DEPARTMENT_H
#define DEPARTMENT_H

using namespace std;
#include <string>
#include <vector>
#include "postman.h"

enum DepartmentType{
    post_office,
    transfer_center
};

class Department
{
private:
    int id;
    string name;
    DepartmentType type;
    vector<Postman> employees;
public:
    Department(int initID, string initName, DepartmentType initType);
    ~Department();
};


#endif
