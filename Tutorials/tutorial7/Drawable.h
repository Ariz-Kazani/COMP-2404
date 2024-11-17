#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

class Drawable
{
public:
    Drawable(int layer);
    virtual void draw(View &) = 0;
    static int compare(Drawable *d1, Drawable *d2);

protected:
    int layer;
};

#endif