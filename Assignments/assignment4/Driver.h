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
    Driver(const string &name, int rating, Size size, const Location &location);
    void draw(View &view);
    bool match(Size size, int rating);

    int getDistance(const Location &location) const;

    static int compRatings(Driver *d1, Driver *d2);
    static void resetNextId();

    void print() const;

private:
    static const char code = 'D';
    static const int driverLayer = 1;
    static int nextId;
    int rating;
    Size s;
};

#endif