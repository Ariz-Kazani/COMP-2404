#include "RideShare.h"

RideShare::RideShare()
{
    customers = new List<Customer *>(Customer::compNames);
    drivers = new List<Driver *>(Driver::compRatings);
    drawables = new List<Drawable *>(Drawable::compare);
}

RideShare::~RideShare()
{
    drawables->clear(); // this has all of the elements so it clears everything

    delete customers;
    delete drivers;
    delete drawables;
}

bool RideShare::addDriver(const string &name, Size size, int rating, const Location &location)
{
    if (rating < 1 || rating > 5 || drivers->isFull() || drawables->isFull())
        return false;
    Driver *d = new Driver(name, rating, size, location);
    drivers->add(d);
    drawables->add(d);
    return true;
}

bool RideShare::addCustomer(const string &name, int rating, const Location &location)
{
    if (rating < 1 || rating > 5 || customers->isFull() || drawables->isFull())
        return false;
    Customer *c = new Customer(name, rating, location);
    customers->add(c);
    drawables->add(c);
    return true;
}

Customer *RideShare::getCustomer(const string &id) const
{
    for (int i = 0; i < customers->getSize(); i++)
    {
        if (customers->get(i)->getID() == id)
        {
            return customers->get(i);
        }
    }
    return nullptr;
}

Driver *RideShare::findRide(int rating, Size size, const Location &location) const
{
    Driver *d = nullptr;
    for (int i = 0; i < drivers->getSize(); i++)
    {
        if (drivers->get(i)->match(size, rating))
        {
            if (d == nullptr || drivers->get(i)->getDistance(location) < d->getDistance(location))
            {
                d = drivers->get(i);
            }
        }
    }
    return d;
}

void RideShare::printCustomers() const
{
    cout << "Printing All Active Customers:" << endl
         << endl;
    for (int i = 0; i < customers->getSize(); i++)
    {
        customers->get(i)->print();
        cout << endl;
    }
}

void RideShare::printDrivers() const
{
    cout << "Printing All Active Drivers:" << endl
         << endl;
    for (int i = 0; i < drivers->getSize(); i++)
    {
        drivers->get(i)->print();
        cout << endl;
    }
}

void RideShare::draw(View &view)
{
    for (int i = 0; i < drawables->getSize(); i++)
    {
        drawables->get(i)->draw(view);
    }
}
