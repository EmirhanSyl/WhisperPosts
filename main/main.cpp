#include <iostream>
#include <string>
#include <vector>
#include "../src/database.cpp"
#include "../src/person.cpp"
#include "../src/admin.cpp"
#include "../src/department.cpp"
#include "../src/user.cpp"
#include "../src/postman.cpp"
#include "../src/address.cpp"
#include "../src/post.cpp"

using namespace std;

int test(){
    Admin admin(0, "Emirhan", "admin", "123");

    Address dept1_addrs("Turkey", "Istanbul", "Kucukcekmece", "Apt-1", 37.7749, -122.4194);
    Address dept2_addrs("Turkey", "Istanbul", "Beyoglu", "pO", 34.7950, -100.4580);

    Department dept1(0, "Europe TM Transfer Center", dept1_addrs, transfer_center);
    Department dept2(1, "Beyoglu Post Office", dept2_addrs, post_office);

    Postman postman1(1, "Ahmet", "ak", "123", &dept1);
    Postman postman2(2, "Mehmet", "kara", "123", &dept1);
    Postman postman3(3, "Ayse", "brown", "123", &dept2);

    dept1.addPostman(&postman1);
    dept1.addPostman(&postman2);
    dept2.addPostman(&postman3);

    User user1(4, "Fatma", "yesil", "123");
    User user2(4, "Hatice", "mavi", "123");

}

int main()
{
    test();
    cout << Database::users.at(1)->getName() << endl;
    return 0;
}