#include "../header/admin.h"

Admin::Admin(int id, const string &name, const string &username, const string &password)
    : Person(id, name, username, password) {}

Admin::Admin() {}
Admin::~Admin() {}

int Admin::createCargoBranch(){
    //Will be implemented later...
}

int Admin::createUser(){
    // Will be implemented later...
}

int Admin::createPostman(){
    // Will be implemented later...
}