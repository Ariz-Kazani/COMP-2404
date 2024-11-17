#include "Drawable.h"

Drawable::Drawable(int layer)
{
    this->layer = layer;
}

int Drawable::compare(Drawable *d1, Drawable *d2)
{
    return d1->layer - d2->layer;
}
