#include "Driver.h"

Driver::Driver(string name, int rating, Size s, Location location) : User(code, nextId, name, rating, location), Drawable(driverLayer)
{
    this->s = s;
    nextId++;
}

int Driver::compNames(Driver *c1, Driver *c2)
{
    return c1->name.compare(c2->name);
}

void Driver::draw(View &view)
{
    view.drawDriver(location.getX(), location.getY(), code);
}

bool Driver::match(Size size, int rating)
{
    return s == size && this->rating + rating <= this->rating + 2;
}

int Driver::getDistance(Location location)
{
    return this->location.getDistance(location);
}

void Driver::resetNextId()
{
    nextId = 0;
}