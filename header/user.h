#ifndef USER_H
#define USER_H

using namespace std;

#include <vector>
#include "person.h"
#include "address.h"

class User : public Person
{
private:
    vector<Address> addresses;
public:
    User(int id, const string &name, const string &username, const string &password);
    User();
    ~User();

    void addAddress(const string &initialCountry, const string &initialCity, 
        const string &initialStreet, const string &initialApartment);

    Address getAddress(int index);
};

#endif