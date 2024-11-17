#include "Customer.h"
int Customer::nextId = 1;

Customer::Customer(string name, int rating, Location location) : User(code, nextId, name, rating, location), Drawable(custLayer)
{
    nextId++;
}

int Customer::compNames(Customer *c1, Customer *c2)
{
    return c1->name.compare(c2->name);
}

void Customer::draw(View &view)
{
    view.drawCustomer(location.getX(), location.getY(), code);
}

void Customer::resetNextId()
{
    nextId = 0;
}
