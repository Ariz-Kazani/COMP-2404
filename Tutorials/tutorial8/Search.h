#include <iostream>
#include <string>
using namespace std;

#include "Episode.h"

class Search {
    friend ostream& operator<<(ostream& ost, const Search&){
        return ost;
    }
    public:
        virtual bool matches(const Episode*) const = 0;
        virtual void print(ostream &ost) const = 0;
};

class H_search : public Search {
    private:
        string host;
    public:
        H_search(string host) : host(host) {}
        bool matches(const Episode* ep) const;
        void print(ostream &ost) const;
};

class C_search : public Search {
    private:
        string category;
    public:
        C_search(string category) : category(category) {}
        bool matches(const Episode* ep) const;
        void print(ostream &ost) const;
};

class And_search : public Search {
    private:
        Search* left;
        Search* right;
    public:
        And_search(Search* left, Search* right) : left(left), right(right) {}
        bool matches(const Episode* ep) const;
        void print(ostream &ost) const;
};

class HorC_search : public Search {
    private:
        string host;
        string category;
    public:
        HorC_search(string host, string category) : host(host), category(category) {}
        bool matches(const Episode* ep) const;
        void print(ostream &ost) const;
};
