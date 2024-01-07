#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include "person.h"
#include "user.h"
#include "admin.h"
#include "department.h"
#include "post.h"

class Database
{
public:
    static vector<Person *> users;
    static vector<Department *> departments;
    static vector<Post *> posts;

    static void initDatabase();
    static Person *login(const string &username, const string &password);
};

#endif