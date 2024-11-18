#ifndef RIDESHARE_H
#define RIDESHARE_H

#include <iostream>
#include <string>

#include "defs.h"
#include "Customer.h"
#include "Driver.h"
#include "List.h"

using namespace std;

class RideShare
{
public:
    RideShare();
    ~RideShare();

    bool addDriver(const string &name, Size size, int rating, const Location &location);
    bool addCustomer(const string &name, int rating, const Location &location);

    Customer *getCustomer(const string &id) const;
    Driver *findRide(int rating, Size size, const Location &locations) const;

    // print functions
    void printCustomers() const;
    void printDrivers() const;

    // other
    void draw(View &);

private:
    List<Customer *> *customers;
    List<Driver *> *drivers;
    List<Drawable *> *drawables;
};

#endif