#include "Customer.h"
int Customer::nextId = 0;

Customer::Customer(const string &name, int rating, const Location &location) : User(code, ++nextId, name, rating, location), Drawable(custLayer) {}

int Customer::compNames(Customer *c1, Customer *c2)
{
    return c1->name.compare(c2->name);
}

void Customer::draw(View &view)
{
    view.drawCustomer(location.getX(), location.getY(), name[0]);
}

void Customer::resetNextId()
{
    nextId = 0;
}

void Customer::print() const
{
    cout << "Customer Details: " << endl;
    User::print();
}