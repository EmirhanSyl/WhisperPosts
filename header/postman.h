#ifndef POSTMAN_H
#define POSTMAN_H

#include "person.h"

class Postman : public Person
{
private:
public:
    Postman(int id, const string &name, const string &username, const string &password, const string &mail);
    Postman();
    ~Postman();

    
};

#endif