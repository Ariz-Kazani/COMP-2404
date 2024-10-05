
#ifndef REPOLIST_H
#define REPOLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include "defs.h"
#include "Repo.h"

using namespace std;

class RepoList
{

public:
    // constructor
    RepoList();

    // destructor
    ~RepoList();

    // other
    bool add(Repo *);
    Repo *get(int);
    Repo *get(string);
    Repo *remove(int);
    Repo *remove(string);
    void clearAll(); // not in specs

    int size();
    bool isFull();

private:
    int numRepos;
    Repo **list;
};
#endif
