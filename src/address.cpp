#include "../header/address.h"

#include <cmath>

Address::Address(const string &initialCountry, const string &initialCity, const string &initialStreet,
                 const string &initialApartment, double initialLatitude, double initialLongitude)
    : country(initialCountry), city(initialCity), street(initialStreet),
      apartment(initialApartment), latitude(initialLatitude), longitude(initialLongitude)
{
    // Will be implemented later...
}

Address::~Address(){}

string Address::getCountry() const
{
    return country;
}

string Address::getCity() const
{
    return city;
}

string Address::getStreet() const
{
    return street;
}

string Address::getApartment() const
{
    return apartment;
}

double Address::getLatitude() const
{
    return latitude;
}

double Address::getLongitude() const
{
    return longitude;
}


double Address::calculateDistance(Address *address)
{
    double dLat = (address->getLatitude() - latitude) * (3.14 / 180.0);
    double dLon = (address->getLongitude() - longitude) * (3.14 / 180.0);

    double a = sin(dLat / 2) * sin(dLat / 2) + cos((latitude) * (3.14 / 180.0)) * cos((address->getLatitude()) * (3.14 / 180.0)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    const double radiusEarth = 6371.0;

    return radiusEarth * c;
}


