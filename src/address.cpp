#include "../header/address.h"

#include <cmath>

Address::Address(const string &initialCountry, const string &initialCity, const string &initialStreet,
                 const string &initialApartment, double initialLatitude, double initialLongitude)
    : country(initialCountry), city(initialCity), street(initialStreet),
      apartment(initialApartment), latitude(initialLatitude), longitude(initialLongitude)
{
    // Will be implemented later...
}

Address::Address(const string &initialCountry, const string &initialCity, const string &initialStreet,
                 const string &initialApartment)
    : country(initialCountry), city(initialCity), street(initialStreet), apartment(initialApartment)
{

    // Generate random values for latitude and longitude
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> latDistribution(-90.0, 90.0);   // Range for latitude
    std::uniform_real_distribution<double> lonDistribution(-180.0, 180.0); // Range for longitude

    latitude = latDistribution(gen);
    longitude = lonDistribution(gen);
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

string Address::to_string() const
{
    return apartment + ", " + street + " - " + city + "/" + country;
}

double Address::getLatitude() const
{
    return latitude;
}

double Address::getLongitude() const
{
    return longitude;
}


double operator-(Address address1, Address address2)
{
    double dLat = (address2.getLatitude() - address1.latitude) * (3.14 / 180.0);
    double dLon = (address2.getLongitude() - address2.longitude) * (3.14 / 180.0);

    double a = sin(dLat / 2) * sin(dLat / 2) + cos((address1.latitude) * (3.14 / 180.0)) * cos((address2.getLatitude()) * (3.14 / 180.0)) * sin(dLon / 2) * sin(dLon / 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));

    const double radiusEarth = 6371.0;

    return radiusEarth * c;
}
