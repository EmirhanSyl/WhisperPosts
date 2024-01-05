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
    void setStateNote(string stateNote);
    string getStateNote();
    
    virtual void handleState(Post &post) = 0;
};

class RecipientPostOfficeState : public PostState
{
public:
    void handleState(Post &post) override;
};

class TransferringState : public PostState
{
public:
    void handleState(Post &post) override;
};

class TargetPostOfficeState : public PostState
{
public:
    void handleState(Post &post) override;
};



class Post
{
private:
    User sender;
    User receiver;
    Department currentDept;
    PostState *currentState;

    vector<pair<Department *, PostState *>> history;
public:
    Post();
    ~Post();

    void setState(PostState *newState);
    void setDepartment(Department *newDepartment);
    void addToHistory();
};


#endif