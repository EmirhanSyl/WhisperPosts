#include "../header/user.h"

#include <iomanip>
#include <random>

User::User(int id, const string &name, const string &username, const string &password)
    : Person(id, name, username, password)
{
    // Will be implemented later...
}

User::User() : Person(0, "", "", "") {}


void User::addAddress(const string &initialCountry, const string &initialCity,
                      const string &initialStreet, const string &initialApartment)
{
    // Random longitute and latitude generation logic
    std::random_device rd;
    std::mt19937 gen(rd());

    // Define the range for latitude and longitude (adjust as needed)
    std::uniform_real_distribution<double> latDist(-90.0, 90.0);
    std::uniform_real_distribution<double> lonDist(-180.0, 180.0);

    // Generate random latitude and longitude values
    double latitude = latDist(gen);
    double longitude = lonDist(gen);


    Address newAddress(initialCountry, initialCity, initialStreet, initialApartment, latitude, longitude);
    addresses.push_back(&newAddress);
}

void User::addAddress(Address *address)
{
    addresses.push_back(address);
}

Address User::getAddress(int index)
{
    if (index >= 0 && index < addresses.size())
    {
        return *addresses[index];
    }
}

void User::removeAddress(int index){
    if (index >= 0 && index < addresses.size())
    {
        addresses.erase(addresses.begin() + index);
    }
    else
    {
        std::cerr << "Invalid index. Please provide a valid index to remove an address." << std::endl;
    }
}

vector<Address *> User::getAddressList(){
    return addresses;
}
