#include "../header/post.h"

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
    cout << "Post is at the Recipient Post Office.\n";
    post.addToHistory();
}

void TransferringState::handleState(Post &post)
{
    cout << "Post is in transit, transferring to the Target Post Office.\n";
    post.addToHistory();
}

void TargetPostOfficeState::handleState(Post &post)
{
    cout << "Post has reached the Target Post Office.\n";
    post.addToHistory();
}



// Implementation of Post class
Post::Post() : currentState(nullptr)
{
    setState(new RecipientPostOfficeState());
}
Post::~Post(){}


void Post::setState(PostState *newState)
{
    currentState = newState;
}

void Post::setDepartment(Department *newDepartment)
{
    currentDept = newDepartment;
}

void Post::addToHistory()
{
    history.push_back(make_pair(currentDept, currentState));
}
