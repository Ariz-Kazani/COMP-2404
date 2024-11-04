
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
    ~Client();
    bool cloneRepo(const GetHub &getHub, int index);
    void printRepo() const;
    void printFileContents(int index) const;

private:
    Repo *repo;
};

#endif