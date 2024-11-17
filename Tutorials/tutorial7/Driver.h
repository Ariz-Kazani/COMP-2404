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
    static int compNames(Driver *d1, Driver *d2);
    void resetNextId();

private:
    const char code = 'D';
    const int driverLayer = 1;
    int nextId = 0;
    Size s;
};

#endif