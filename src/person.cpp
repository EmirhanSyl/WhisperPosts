#include "../header/person.h"
#include "../header/database.h"
#include <iostream>

using namespace std;

// Constructor
Person::Person(int id, const string &name, const string &username, const string &password)
    : id(id), name(name), username(username), password(password)
{
    Database::users.push_back(this);
}
Person::Person() {}
Person::~Person() {}

// Getter functions
int Person::getId() const
{
    return id;
}

string Person::getName() const
{
    return name;
}

string Person::getUsername() const
{
    return username;
}

string Person::getPassword() const
{
    return password;
}


// Setter fonksiyonları
void Person::setId(int newId)
{
    id = newId;
}

void Person::setName(const string &newName)
{
    name = newName;
}

void Person::setUsername(const string &newUsername)
{
    username = newUsername;
}

void Person::setPassword(const string &newPassword)
{
    password = newPassword;
}
