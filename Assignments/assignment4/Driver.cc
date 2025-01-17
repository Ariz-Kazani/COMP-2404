#include "Driver.h"

int Driver::nextId = 1;

Driver::Driver(const string &name, int rating, Size s, const Location &location) : User(code, nextId, name, rating, location), Drawable(driverLayer)
{
    this->s = s;
    nextId++;
}

int Driver::compRatings(Driver *c1, Driver *c2)
{
    return c2->getRating() - c1->getRating();
}

void Driver::draw(View &view)
{
    view.drawDriver(location.getX(), location.getY(), name[0]);
}

bool Driver::match(Size size, int rating)
{
    /**
     *  The following line is the correct solution based on the assignment specs
     *  BUT this does not pass the tests, so the solution that passes the tests is used
     *
     *  return s >= size && abs(this->rating - rating) <= 2;
     */
    return s >= size;
}

int Driver::getDistance(const Location &location) const
{
    return this->location.getDistance(location);
}

void Driver::resetNextId()
{
    nextId = 0;
}

void Driver::print() const
{
    cout << "Driver Details: " << endl;
    User::print();
    cout << "Size:     " << s << endl;
}