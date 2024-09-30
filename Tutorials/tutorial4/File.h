#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>
#include "Date.h"

using namespace std;

class File
{
public:
    File(string name, string content, Date &date);

    // getters
    Date *getDate();   // not in specs
    string *getName(); // not in specs
    bool lessThan(const Date &date);

    // print statements
    void print();
    void printContents();

private:
    string name;
    string content;
    Date date;
};
#endif