#ifndef CAR_H
#define CAR_H
#include<vector>
#include <QtPositioning>
#include <QtLocation>
#include <QtPositioning>
#include <string>

using std::vector;
using std::string;

/**
 * @brief The Car class describes a car in our map, each car can be moving or not, it release some signals , and scan signals from other cars in permanance
 * when a signal is detected, a car store the acr origin in connectedCars , which means they can communicate,
 * If car A has Car B in it's connectedCars, it means A can receive from B and vice versa
 * The communication is based on distance between cars, and the signals strength sent
 */
class Car
{
public:
    Car(const QGeoCoordinate&  location);
    double getDistance(const Car&)const;
    int getId()const;
    vector<Car*> getConnectedCars()const;

    //E
    string broadcastSignal();
private:
    //Current location of a car
    QGeoCoordinate  location;

    //When car gets closer at a certain distance (5meters) they gets connected, and they store eachother on connectedCars
    vector<Car*>connectedCars;

    //is moving is true only when the car is moving
    bool isMoving;

    //To identify a car
    int id;

    // Static counter for assigning unique IDs
    static int nextCarID;


};

#endif // CAR_H


