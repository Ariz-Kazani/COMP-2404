#include "User.h"

User::User(char code, int codeNum, string name, int rating, Location location)
{
    id = code + to_string(codeNum);
    this->name = name;
    this->rating = rating;
    this->location = location;
}

bool User::setRating(int rating)
{
    if (rating < 1 || rating > 5)
    {
        return false;
    }

    this->rating = rating;
}

bool User::setLocation(Location location)
{
    this->location = location;
}

bool User::setLocation(int x, int y)
{
    this->location = Location(x, y);
}

void User::print()
{
    cout << "User ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Rating: " << rating << endl;
    cout << "Location: ";
    location.print();
}