#include "User.h"

User::User(char code, int codeNum, const string &name, int rating, const Location &location)
{
    string ts = "";
    ts.push_back(code);
    id = ts + to_string(codeNum);
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

void User::setLocation(const Location &location)
{
    this->location = Location(location);
}

void User::setLocation(int x, int y)
{
    this->location = Location(x, y);
}

void User::print() const
{
    cout << "User ID:  " << id << endl;
    cout << "Name:     " << name << endl;
    cout << "Rating:   " << rating << endl;
    cout << "Location: ";
    location.print();
    cout << endl;
}