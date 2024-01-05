#ifndef ADDRESS_H
#define ADDRESS_H

using namespace std;
#include <string>
#include <iostream>

class Address
{
private:
    const string country;
    const string city;
    const string street;
    const string apartment;
    const double latitude;
    const double longitude;

public:
    Address(const string &initialCountry, const string &initialCity, const string &initialStreet,
            const string &initialApartment, double initialLatitude, double initialLongitude);
    ~Address();

    // Getter functions
    string getCountry() const;
    string getCity() const;
    string getStreet() const;
    string getApartment() const;
    double getLatitude() const;
    double getLongitude() const;

    double calculateDistance(Address *address);

    bool operator<=(Address *address);
    bool operator>=(Address *address);
};


#endif