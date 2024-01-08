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

int Display();

int main()
{
    test();
    Display();
    //cout << Database::users.at(1)->getName() << endl;
    return 0;
}

int Display()
{
    Person *account;
    int option;
    int isLoggedIn = 0;

    while (true)
    {
        if (isLoggedIn && (instanceof <Admin>(account)))
        {
            printf("\n--------- Welcome Admin ---------\n", account->getName());

            int choice;

            cout << "\n1- Create Postman" << endl;
            cout << "2- Create Department" << endl;
            cout << "3- Show All Departments" << endl;
            cout << "4- Show All Postmen" << endl;
            cout << "5- Change Postman Department" << endl;
            cout << "6- Fire Postman" << endl;
            cout << "7- Logout" << endl;

            cout << "\nSelect an option : ";
            cin >> choice;

            switch (choice)
            {
            case 1:

                break;

            case 2:
                
                break;

            case 3:
                
                break;

            case 4:
                
                break;

            case 5:
                
                break;

            case 6:
                
                break;

            case 7:
                
                break;

            default:
                printf("\nInvalid option. Please select [1-7]\n");
                while (getchar() != '\n');
                break;
            }
        }
        else if (isLoggedIn && (instanceof <Postman>(account)))
        {
            int switchOption = 0;

            cout << "\n--------- Welcome " << account->getName() << " --------- " << endl;

            cout << "\n1- Show account information" << endl;
            cout << "2- Register new post" << endl;
            cout << "3- View all posts in department" << endl;
            cout << "4- Update post status" << endl;
            cout << "5- Logout" << endl;

            cout << "\nSelect an option : ";
            cin >> switchOption;

            switch (switchOption)
            {
            case 1:

                break;

            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            case 5:
                isLoggedIn = 0;
                break;
            }
        }
        else if (isLoggedIn && (instanceof <User>(account)))
        {
            int switchOption = 0;

            cout << "\n--------- Welcome " << account->getName() << " --------- " << endl;

            cout << "\n1- Show account information" << endl;
            cout << "2- Add new address" << endl;
            cout << "3- Delete existed address" << endl;
            cout << "3- Register new post" << endl;
            cout << "4- View post status" << endl;
            cout << "5- Logout" << endl;

            cout << "\nSelect an option : ";
            cin >> switchOption;

            switch (switchOption)
            {
            case 1:
                
                break;

            case 2:
                
                break;

            case 3:
                
                break;

            case 4:
                
                break;

            case 5:
                isLoggedIn = 0;
                break;
            }
        }
        else
        {
            cout << "\n--------- WELCOME TO VOTING SYSTEM ---------\n";

            cout << "1- Login\n";
            cout << "2- Register\n";
            cout << "3- Exit\n";

            cout << "\nSelect an option: ";
            cin >> option;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

            string name;
            string username;
            string password;
            string mail;

            switch (option)
            {
            case 1:
                cout << "\nEnter your username: ";
                getline(cin, username);

                cout << "Enter your password: ";
                getline(cin, password);

                
                cout << "\nLogging in...\n\n";
                account = Database::login(username, password);
                if (account != nullptr)
                {
                    isLoggedIn = true;
                    break;
                }
                else
                {
                    cout << "User not found! Please try again.\n";
                }
                break;

            case 2:
                cout << "\nEnter your name: ";
                getline(cin, name);

                cout << "Enter your username: ";
                getline(cin, username);

                cout << "Enter your password: ";
                getline(cin, password);

                cout << "Enter your mail: ";
                getline(cin, mail);

                account = new User(Database::users.size() + 1, name, username, password);
                cout << "\nAccount created successfully!\n\n";
                isLoggedIn = true;
                break;

            case 3:
                cout << "\n------------ Goodbye! ------------\n";
                return 0;

            default:
                cout << "Invalid option. Please select 1, 2, or 3.\n";
            }
        }
    }
}