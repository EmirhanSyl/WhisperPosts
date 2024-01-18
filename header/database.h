#ifndef DATABASE_H
#define DATABASE_H

#include <algorithm>
#include <vector>
#include <fstream>
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
    static Person *login(const string username, const string password);
    static Person *createUser(string name, string username, string password);
    static Person *createPostman(string name, Department *department);
    static Department *createDepartment(string name, Address address, DepartmentType type);

    static void removeUser(int id);
    static Post **findPostsByUser(int userID, int &size);
    static void writePostmanDataToFile(string filename);
};

#endif