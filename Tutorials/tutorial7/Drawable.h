#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

class Drawable
{
public:
    Drawable(int layer) : layer(layer) {}
    virtual void draw(View &) = 0;
    static int compare(Drawable *d1, Drawable *d2) { return d1->layer - d2->layer; }

protected:
    int layer;
};

#endif