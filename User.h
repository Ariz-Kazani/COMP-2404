#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
#include "Location.h"

using namespace std;

class User
{
public:
    // getters
    User(char code, int codeNum, string name, int rating, Location);
    string getID() const { return id; }
    string getName() const { return name; }
    int getRating() const { return rating; }
    Location getLocation() const { return location; }

    // setters
    bool setRating(int rating);
    void setLocation(Location location);
    void setLocation(int x, int y);

    // other
    void print();

protected:
    string id;
    string name;
    int rating;
    Location location;
};

#endif