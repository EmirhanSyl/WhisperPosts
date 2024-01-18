#include "../header/database.h"

vector<Person *> Database::users;
vector<Post *> Database::posts;
vector<Department *> Database::departments;

void Database::initDatabase(){
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

template <typename Base, typename Derived>
static bool instanceof (const Derived *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

Person *Database::login(const string username, const string password)
{
    for (Person *p : users)
    {
        if (p->getUsername() == username && p->getPassword() == password)
        {
            return p;
        }
    }
    
    return nullptr;
}

Person *Database::createUser(string name, string username, string  password){
    Person *newPerson = new User(users.size(), name, username, password);

    return newPerson;
}

Person *Database::createPostman(string name, Department *department)
{
    Postman *newPostman = new Postman(Database::users.size(), name, name, "123", department);
    department->addPostman(newPostman);
    return newPostman;
}

Department *Database::createDepartment(string name, Address address, DepartmentType type){
    return new Department(departments.size(), name, address, type);
}

void Database::removeUser(int id){

    users.erase(
        std::remove_if(users.begin(), users.end(),
                       [id](const Person *p)
                       {
                           return p->getId() == id;
                       }),
        users.end());
}

Post **Database::findPostsByUser(int userID, int &size){
    Post **users_posts = (Post **)malloc(sizeof(Post*));
    int foundPosts = 0;
    for (int i = 0; i < Database::posts.size(); i++)
    {
        if (Database::posts[i]->sender.getId() == userID)
        {
            users_posts[foundPosts] = Database::posts[i];
            foundPosts++;
            users_posts = (Post **)realloc(users_posts, sizeof(Post*) * foundPosts);
        }
    }

    foundPosts = size;
    return users_posts;
}

void Database::writePostmanDataToFile(string filename)
{
    std::ofstream outputFile(filename + "txt");

    if (!outputFile.is_open())
    {
        std::cerr << "Error opening file " << filename << std::endl;
        return;
    }

    for (Person *person : users)
    {
        if (instanceof<Postman>(person))
        {
            Postman *postman = dynamic_cast<Postman *>(person);
            outputFile << "Postman ID: " << postman->getId() << "\t";
            outputFile << "Name: " << postman->getName() << "\t";
            outputFile << "Department: " << postman->getDepartment()->getName();
            outputFile << std::endl;
        }
        
    }

    outputFile.close();
}