#ifndef ADDRESS_H
#define ADDRESS_H

using namespace std;
#include <string>
#include <iostream>
#include <random>

class Address
{
private:
    const string country;
    const string city;
    const string street;
    const string apartment;
    double latitude;
    double longitude;

public:
    Address(const string &initialCountry, const string &initialCity, const string &initialStreet,
            const string &initialApartment, double initialLatitude, double initialLongitude);
    Address(const string &initialCountry, const string &initialCity, const string &initialStreet,
            const string &initialApartment);
    ~Address();

    // Getter functions
    string getCountry() const;
    string getCity() const;
    string getStreet() const;
    string getApartment() const;
    string to_string() const;
    double getLatitude() const;
    double getLongitude() const;

    friend double operator-(Address address1, Address address2);
};


#endif