#ifndef DEPARTMENT_H
#define DEPARTMENT_H

using namespace std;
#include <string>
#include <vector>
#include "postman.h"
#include "address.h"

enum DepartmentType{
    post_office,
    transfer_center
};

class Department
{
private:
    int id;
    string name;
    Address address;
    DepartmentType type;
    vector<Postman *> employees; // Not sure?
public:
    Department(int initID, string initName, Address initAddress, DepartmentType initType);
    ~Department();

    void addPostman(Postman *postman); 
    Postman *getPostman(int index);
};


#endif
