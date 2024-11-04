
#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include <iomanip>

#include "GetHub.h"

using namespace std;

class Client
{
public:
    // constructor
    Client();
    void cloneRepo(GetHub &getHub, int index);
    void printRepo() const;
    void printFileContents() const;

private:
    string name;
    string email;
    string password;
    GetHub getHub;
};

#endif