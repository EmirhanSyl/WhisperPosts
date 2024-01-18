// sender, reciever, letter info?, state, current address, cargo branch, notes
#ifndef POST_H
#define POST_H

using namespace std;
#include <utility> // for std::pair

#include "user.h"
#include "postman.h"
#include "address.h"
#include "department.h"

class Post; //fwrd decleration

// State Machine Design Pattern
class PostState
{
private:
    string stateNote;

public:
    string stateName;
    void setStateNote(string stateNote);
    string getStateNote();

    virtual void handleState(Post &post) = 0;
    virtual void complateState(Post &post, string stateNote) = 0;
};

class RecipientPostOfficeState : public PostState
{
public:
    void handleState(Post &post) override;
    void complateState(Post &post, string stateNote) override;
};

class TransferringState : public PostState
{
public:
    void handleState(Post &post) override;
    void complateState(Post &post, string stateNote) override;
};

class TargetPostOfficeState : public PostState
{
public:
    void handleState(Post &post) override;
    void complateState(Post &post, string stateNote) override;
};

class DoneState : public PostState
{
public:
    void handleState(Post &post) override;
    void complateState(Post &post, string stateNote) override;
};

class Post
{
private:
    
public:
    int id;
    User sender;
    Address senderAddress;
    Address recieverAddress;
    Department *currentDept;
    PostState *currentState;

    vector<pair<Department *, PostState *>> history;

    Post(int id, User sender, Address senderAddress, Address recieverAddress, Department *currentDept, PostState *currentState);
    ~Post();

    void setState(PostState *newState);
    
    void setDepartment(Department *newDepartment);
    void addToHistory();
};

class PostHandler
{
public:
    static Post *createPost(User sender, Address senderAddress, Address recieverAddress);
    static Department *calculateRoute(Post post, DepartmentType type);
};



#endif