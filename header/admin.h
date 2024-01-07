#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"

class Admin : public Person
{
private:
    

public:
    Admin(int id, const string &name, const string &username, const string &password);
    Admin();
    ~Admin();

    int createCargoBranch();
    int createUser();
    int createPostman();
};

#endif