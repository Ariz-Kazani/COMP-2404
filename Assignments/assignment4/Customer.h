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
    Customer(const string &name, int rating, const Location &location);
    void draw(View &view);
    static int compNames(Customer *c1, Customer *c2);
    void resetNextId();
    void print() const;

private:
    static const char code = 'C';
    static const int custLayer = 3;
    static int nextId;
};

#endif