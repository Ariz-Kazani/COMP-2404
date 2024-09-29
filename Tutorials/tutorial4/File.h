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
    bool lessThan(Date &date);
    void print();
    void printContents();

private:
    string name;
    string content;
    Date date;
};
#endif