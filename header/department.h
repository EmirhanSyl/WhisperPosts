#ifndef DEPARTMENT_H
#define DEPARTMENT_H

using namespace std;
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

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
public:
    vector<Postman *> employees; 

    Department(int initID, string initName, Address initAddress, DepartmentType initType);
    ~Department();

    static unordered_map<DepartmentType, string> department_type_names;

    int getId() const;
    void setId(int newId);

    string getName() const;
    void setName(const string newName);

    Address getAddress() const;
    void setAddress(Address newAddress);

    DepartmentType getType() const;
    void setType(DepartmentType newType);

    void addPostman(Postman *postman); 
    Postman *getPostman(int index);
};


#endif
