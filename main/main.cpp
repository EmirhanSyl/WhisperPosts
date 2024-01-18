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

int test()
{
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
    //test();
    Admin admin(0, "Emirhan", "admin", "123");
    User user(1, "emir", "emirs", "123");
    Address dept1_addrs("Turkey", "Istanbul", "Kucukcekmece", "Apt-1", 37.7749, -122.4194);
    Address dept2_addrs("Turkey", "Istanbul", "Beyoglu", "pO", 34.7950, -100.4580);
    Address dept3_addrs("Turkey", "Istanbul", "Arnavutkoy", "ApO", 36.7550, -102.4000);

    Department dept1(0, "Europe TM Transfer Center", dept1_addrs, transfer_center);
    Department dept2(1, "Beyoglu Post Office", dept2_addrs, post_office);
    Department dept3(2, "Arnavutkoy Post Office", dept2_addrs, post_office);

    Postman postman1(2, "Ahmet", "ak", "123", &dept1);
    Postman postman2(3, "Mehmet", "kara", "123", &dept2);
    Postman postman3(4, "Ayse", "brown", "123", &dept3);

    dept1.addPostman(&postman1);
    dept2.addPostman(&postman2);
    dept3.addPostman(&postman3);

    Display();
    return 0;
}

void showAllDepartments()
{
    for (int i = 0; i < Database::departments.size(); i++)
    {
        cout << "index : " << i << endl;
        cout << "Department ID: " << Database::departments[i]->getId() << endl;
        cout << "Department Name: " << Database::departments[i]->getName() << endl;
        cout << "Department Address: " << Database::departments[i]->getAddress().to_string() << endl;
        cout << "Department Type: " << Department::department_type_names[static_cast<DepartmentType>(Database::departments[i]->getId())] << endl;
        cout << "Department Worker Count: " << Database::departments[i]->employees.size() << endl;
        cout << "--------------------------------------------" << endl;
    }
}

void showAllPostmen(){
    for (int i = 0; i < Database::users.size(); i++)
    {
        if (instanceof<Postman>(Database::users[i]))
        {
            Postman *postman = dynamic_cast<Postman *>(Database::users[i]);

            cout << "index : " << i << endl;
            cout << "Postman ID: " << postman->getId() << endl;
            cout << "Postman Name: " << postman->getName() << endl;
            cout << "Postman Department: " << postman->getDepartment()->getName() << endl;
            cout << "--------------------------------------------" << endl;
        }
    }
}

Address *createAddress(){
    string country;
    string city;
    string street;
    string apartment;

    cout << "\nAdd an address";
    cout << "\nCountry: ";
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getline(cin, country);

    cout << "City: ";
    getline(cin, city);
    
    cout << "Street: ";
    getline(cin, street);

    cout << "Apartment: ";
    getline(cin, apartment);

    return new Address(country, city, street, apartment);
}

void showAllAddresses(User *user){
    for (int i = 0; i < user->getAddressList().size(); i++)
    {
        cout << "Index: " << i << endl;
        cout << "Address: " << user->getAddress(i).to_string() << endl;
        cout << "--------------------------------------------" << endl;
    }
}

void viewPostsInDepertment(Department *dept){
    for (int i = 0; i < Database::posts.size(); i++)
    {
        if (Database::posts[i]->currentDept->getId() == dept->getId())
        {
            cout << "index : " << i << endl;
            cout << "Post ID: " << Database::posts[i]->id << endl;
            cout << "Sender Name: " << Database::posts[i]->sender.getName() << endl;
            cout << "Sender Address: " << Database::posts[i]->senderAddress.to_string() << endl;
            cout << "Receiver Address: " << Database::posts[i]->recieverAddress.to_string() << endl;
            cout << "Current Department: " << Database::posts[i]->currentDept->getName() << endl;
            cout << "Current State: " << Database::posts[i]->currentState->stateName << endl;
            cout << "--------------------------------------------" << endl;
        }
        
    }
    
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
            Admin *admin = dynamic_cast<Admin *>(account);
            printf("\n--------- Welcome Admin ---------\n", account->getName());

            int choice;
            int secChoice;
            int thirdChoice;

            cout << "\n1- Create Postman" << endl;
            cout << "2- Create Department" << endl;
            cout << "3- Show All Departments" << endl;
            cout << "4- Show All Postmen" << endl;
            cout << "5- Change Postman Department" << endl;
            cout << "6- Fire Postman" << endl;
            cout << "7- Logout" << endl;

            cout << "\nSelect an option : ";
            cin >> choice;

            string name;
            string username;

            Address *department_address;
            DepartmentType dept_type;

            Postman *postman;

            switch (choice)
            {
            case 1:
                cout << "\nEnter postman name: " << flush;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                getline(cin, name);

                showAllDepartments();
                cout << "Choose Postman Department: ";
                cin >> secChoice;
                if (secChoice < 0 || secChoice >= Database::departments.size())
                {
                    cout << "Please give department index carefully";
                    break;
                }

                if (Database::createPostman(name, Database::departments[secChoice]) != nullptr)
                {
                    cout << "Postman added successfuly! username: " << name << ", password: 123" << endl;
                }
                else
                {
                    cout << "Something went wrong..." << endl;
                }

                cout << "\nAccount created successfully!\n\n";
                break;

            case 2:
                cout << "\nEnter department name: " << flush;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                getline(cin, name);

                department_address = createAddress();

                cout << "Select Department type (0-Post Office, 1-Transfer Center): ";
                cin >> secChoice;

                dept_type = static_cast<DepartmentType>(secChoice);

                if (Database::createDepartment(name, *department_address, dept_type) != nullptr)
                {
                    cout << "Department added successfuly! username: " << name << ", password: 123" << endl;
                }
                else
                {
                    cout << "Something went wrong..." << endl;
                }

                break;

            case 3:
                showAllDepartments();
                break;

            case 4:
                showAllPostmen();
                break;

            case 5:
                showAllPostmen();
                cout << "Please select a postman to change depertment: ";
                cin >> secChoice;

                if (secChoice < 0 || secChoice >= Database::users.size() || !instanceof<Postman>(Database::users[secChoice]))
                {
                    cout << "Please give postman index carefully";
                    break;
                }

                cout << "\n" << endl;
                showAllDepartments();
                cout << "Please select new department for postman: ";
                cin >> thirdChoice;

                if (thirdChoice < 0 || thirdChoice >= Database::departments.size())
                {
                    cout << "Please give department index carefully";
                    break;
                }

                postman = dynamic_cast<Postman *>(Database::users[secChoice]);
                postman->setDepartment(Database::departments[thirdChoice]);
                break;

            case 6:
                showAllPostmen();
                cout << "Please select a postman to fire: ";
                cin >> secChoice;

                if (secChoice < 0 || secChoice >= Database::users.size() || ! instanceof <Postman>(Database::users[secChoice]))
                {
                    cout << "Please give postman index carefully";
                    break;
                }

                Database::removeUser(Database::users[secChoice]->getId());
                cout << "Postman fired successfully!";
                break;

            case 7:
                isLoggedIn = 0;
                break;

            default:
                printf("\nInvalid option. Please select [1-7]\n");
                while (getchar() != '\n')
                    ;
                break;
            }
        }
        else if (isLoggedIn && (instanceof <Postman>(account)))
        {
            Postman *postman = dynamic_cast<Postman *>(account);
            int choice = 0;
            int secChoice = 0;
            string stateNote;

            cout << "\n--------- Welcome " << account->getName() << " --------- " << endl;

            cout << "\n1- Show account information" << endl;
            cout << "2- View all posts in department" << endl;
            cout << "3- Update post status" << endl;
            cout << "4- Logout" << endl;

            cout << "\nSelect an option : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nName : " << postman->getName() << endl;
                cout << "Username : " << postman->getUsername() << endl;
                cout << "Password : " << postman->getPassword() << endl;
                cout << "Mail : " << postman->getDepartment()->getName() << endl;
                break;

            case 2:
                viewPostsInDepertment(postman->getDepartment());
                break;

            case 3:
                viewPostsInDepertment(postman->getDepartment());
                cout << "Please select a post to update its status: ";
                cin >> secChoice;

                if (secChoice < 0|| secChoice > Database::posts.size())
                {
                    cout << "Please enter index carefully!" << endl;
                }
                cout << "Enter a state note for user:" << endl;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                getline(cin, stateNote);

                Database::posts[secChoice]->currentState->complateState(*Database::posts[secChoice], stateNote);
                break;

            case 4:
                isLoggedIn = 0;
                break;
            }
        }
        else if (isLoggedIn && (instanceof <User>(account)))
        {
            User *user = dynamic_cast<User *>(account);
            
            cout << "\n--------- Welcome " << account->getName() << " --------- " << endl;

            cout << "\n1- Show account information" << endl;
            cout << "2- Add new address" << endl;
            cout << "3- Show all address" << endl;
            cout << "4- Delete existed address" << endl;
            cout << "5- Register new post" << endl;
            cout << "6- View post status" << endl;
            cout << "7- Logout" << endl;

            int choice = 0;
            int secChoice = 0;
            Address *address;

            cout << "\nSelect an option : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "\nName : " << user->getName() << endl;
                cout << "Username : " << user->getUsername() << endl;
                cout << "Password : " << user->getPassword() << endl;
                break;

            case 2:
                address = createAddress();
                user->addAddress(address);
                break;

            case 3:
                showAllAddresses(user);
                break;

            case 4:
                showAllAddresses(user);
                cout << "Select address to delete: ";
                cin >> secChoice;

                if (secChoice < 0 && secChoice >= user->getAddressList().size())
                {
                    cout << "Please give address index carefully";
                    break;
                }
                
                user->removeAddress(secChoice);
                break;

            case 5:
                if (user->getAddressList().size() == 0)
                {
                    cout << "You have no recorded address. Please add one first." << endl;
                    break;
                }
                
                showAllAddresses(user);
                cout << "Select address: ";
                cin >> secChoice;

                if (secChoice < 0 && secChoice >= user->getAddressList().size())
                {
                    cout << "Please give address index carefully";
                    break;
                }

                cout << "\nPlease enter reciever address:";
                address = createAddress();
                PostHandler::createPost(*user, user->getAddress(secChoice), *address);
                break;

            case 6:
                for (int i = 0; i < Database::posts.size(); i++)
                {
                    if (Database::posts[i]->sender.getId() == user->getId())
                    {
                        cout << "index : " << i << endl;
                        cout << "Post ID: " << Database::posts[i]->id << endl;
                        cout << "Sender Name: " << Database::posts[i]->sender.getName() << endl;
                        cout << "Sender Address: " << Database::posts[i]->senderAddress.to_string() << endl;
                        cout << "Receiver Address: " << Database::posts[i]->recieverAddress.to_string() << endl;
                        cout << "Current Department: " << Database::posts[i]->currentDept->getName() << endl;
                        cout << "Current State: " << Database::posts[i]->currentState->stateName << endl;
                        cout << "--------------------------------------------" << endl;
                    }
                }

                cout << "Select an index to see its history: " << endl;
                cin >> secChoice;

                if (secChoice < 0 || secChoice > Database::posts.size() || Database::posts[secChoice]->sender.getId() != user->getId())
                {
                    cout << "Please select index carefully!" << endl;
                    break;
                }

                cout << "---------------------- DETAILS -------------------" << endl;
                cout << "index : " << secChoice << endl;
                cout << "Post ID: " << Database::posts[secChoice]->id << endl;
                cout << "Sender Name: " << Database::posts[secChoice]->sender.getName() << endl;
                cout << "Sender Address: " << Database::posts[secChoice]->senderAddress.to_string() << endl;
                cout << "Receiver Address: " << Database::posts[secChoice]->recieverAddress.to_string() << endl;
                cout << "Current Department: " << Database::posts[secChoice]->currentDept->getName() << endl;
                cout << "Current State: " << Database::posts[secChoice]->currentState->stateName << endl;
                cout << "\n ------------------------- HISTORY --------------------" << endl;

                for (int i = 0; i < Database::posts[secChoice]->history.size(); i++)
                {
                    cout << "\nDepartment - " << i << ": " << Database::posts[secChoice]->history.at(i).first->getName() << endl;
                    cout << "State - " << i << ": " << Database::posts[secChoice]->history.at(i).second->stateName << endl;
                    cout << "State Note - " << i << ": " << Database::posts[secChoice]->history.at(i).second->getStateNote() << endl;
                }
                
                cout << "--------------------------------------------" << endl;

                break;

            case 7:
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

                account = Database::createUser(name, username, password);
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