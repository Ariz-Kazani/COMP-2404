#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>

#include "User.h"
#include "Drawable.h"
#include "View.h"

using namespace std;

class Driver : public User, public Drawable
{
public:
    Driver(string name, int rating, Size size, Location location);
    void draw(View &view);
    bool match(Size size, int rating);
    int getDistance(Location location);
    static int compRatings(Driver *d1, Driver *d2);
    void resetNextId();

private:
    static const char code = 'D';
    static const int driverLayer = 1;
    static int nextId;
    int rating;
    Size s;
};

#endif