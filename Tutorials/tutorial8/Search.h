#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <string>
using namespace std;

#include "Episode.h"

class Search
{
    friend ostream &operator<<(ostream &ost, const Search &s);

public:
    virtual bool matches(const Episode *) const = 0;
    virtual void print(ostream &ost) const = 0;
};

class H_Search : public Search
{
private:
    string host;

public:
    H_Search(const string &host) : host(host) {}
    bool matches(const Episode *ep) const;
    void print(ostream &ost) const;
};

class C_Search : public Search
{
private:
    string category;

public:
    C_Search(const string &category) : category(category) {}
    bool matches(const Episode *ep) const;
    void print(ostream &ost) const;
};

class HorC_Search : public Search
{
private:
    string host;
    string category;

public:
    HorC_Search(const string &host, const string &category) : host(host), category(category) {}
    bool matches(const Episode *ep) const;
    void print(ostream &ost) const;
};

#endif