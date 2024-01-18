#include "../header/post.h"
#include "../header/database.h"
#include <cfloat>

void PostState::setStateNote(string stateNote)
{
    this->stateNote = stateNote;
}

string PostState::getStateNote()
{
    return stateNote;
}


// State Handlers
void RecipientPostOfficeState::handleState(Post &post)
{
    stateName = "Recipient Post Office State";
    cout << "Post is at the Recipient Post Office.\n";
    post.addToHistory();
}
void RecipientPostOfficeState::complateState(Post &post, string stateNote)
{
    setStateNote(stateNote);
    post.currentDept = PostHandler::calculateRoute(post, transfer_center);
    post.setState(new TransferringState());
}

void TransferringState::handleState(Post &post)
{
    stateName = "Transferring State";
    cout << "Post is in transit, transferring to the Target Post Office.\n";
    post.addToHistory();
}
void TransferringState::complateState(Post &post, string stateNote)
{
    setStateNote(stateNote);
    Department *closestDepartment;
    double closest = DBL_MAX;

    for (Department *dept : Database::departments)
    {
        if (dept->getType() == post_office)
        {
            if (abs(dept->getAddress() - post.recieverAddress) <= closest)
            {
                closest = abs(dept->getAddress() - post.recieverAddress);
                closestDepartment = dept;
            }
        }
    }
    post.currentDept = closestDepartment;
    post.setState(new TargetPostOfficeState());
}

void TargetPostOfficeState::handleState(Post &post)
{
    stateName = "Target Post Office State";
    cout << "Post has reached the Target Post Office.\n";
    post.addToHistory();
}
void TargetPostOfficeState::complateState(Post &post, string stateNote)
{
    setStateNote(stateNote);
    post.currentDept = nullptr;
    post.setState(new DoneState());
}

void DoneState::handleState(Post &post)
{
    stateName = "Done";
    cout << "Post Sent.\n";
    post.addToHistory();
}
void DoneState::complateState(Post &post, string stateNote)
{
    setStateNote(stateNote);
}


// Implementation of Post class
Post::Post(int id, User sender, Address senderAddress, Address recieverAddress, Department *currentDept, PostState *currentState)
    : id(id), sender(sender), senderAddress(senderAddress), recieverAddress(recieverAddress), currentDept(currentDept)
{
    setState(currentState);
}
Post::~Post(){}


void Post::setState(PostState *newState)
{
    currentState = newState;
    currentState->handleState(*this);
}

void Post::setDepartment(Department *newDepartment)
{
    currentDept = newDepartment;
}

void Post::addToHistory()
{
    history.push_back(make_pair(currentDept, currentState));
}


Post *PostHandler::createPost(User sender, Address senderAddress, Address recieverAddress){
    Department *closestDepartment;
    double closest = DBL_MAX;

    for(Department *dept : Database::departments){
        if (dept->getType() == post_office)
        {
            if (abs(dept->getAddress() - senderAddress) <= closest)
            {
                closest = abs(dept->getAddress() - senderAddress);
                closestDepartment = dept;
            }
        }
    }

    Post *newPost = new Post(Database::posts.size(), sender, senderAddress, recieverAddress, closestDepartment, new RecipientPostOfficeState());
    newPost->currentState->setStateNote("Post Sent!");
    Database::posts.push_back(newPost);
    return newPost;
}

Department *PostHandler::calculateRoute(Post post, DepartmentType type){
    Department *closestDepartment;
    double closest = DBL_MAX;

    for (Department *dept : Database::departments)
    {
        if (dept->getType() == type)
        {
            if (abs(dept->getAddress() - post.currentDept->getAddress()) <= closest)
            {
                closest = abs(dept->getAddress() - post.currentDept->getAddress());
                closestDepartment = dept;
            }
        }
    }

    return closestDepartment;
}