#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>

#include "User.h"
#include "Drawable.h"
#include "View.h"

using namespace std;

class Customer : public User, public Drawable
{
public:
    Customer(string name, int rating, Location location);
    void draw(View &view);
    static int compNames(Customer *c1, Customer *c2);
    void resetNextId();

private:
    const char code = 'C';
    const int custLayer = 3;
    int nextId = 0;
};

#endif