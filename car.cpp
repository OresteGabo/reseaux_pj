#include "car.h"

int Car::nextCarID = 1; // Initialize the static variable

Car::Car(const QGeoCoordinate& location)
    : location(location), isMoving(false)
{
    id = nextCarID++;
}

double Car::getDistance(const Car& otherCar) const
{
    // Calculate the distance between this car and another car
    double distance = location.distanceTo(otherCar.location);
    return distance;
}

int Car::getId() const
{
    return id;
}

std::vector<Car*> Car::getConnectedCars() const
{
    return connectedCars;
}

string Car::broadcastSignal()
{
    return "I am the car ";
}
