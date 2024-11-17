#include "User.h"
#include <string>

User::User(char code, int codeNum, std::string name, int rating, Location location)
{
    std::string ts = "";
    ts.push_back(code);
    // id = code + to_string(codeNum);
    id = ts + std::to_string(codeNum);
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
    return true;
}

void User::setLocation(Location location)
{
    this->location = location;
}

void User::setLocation(int x, int y)
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