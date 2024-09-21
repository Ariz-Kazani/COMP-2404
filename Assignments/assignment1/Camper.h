#ifndef CAMPER_H
#define CAMPER_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Camper
{
public:
    // constructor
    Camper::Camper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out);
    Camper::Camper();

    // getters
    Date getStartDate(); // not in specs
    Date getEndDate();   // not in specs
    string getName();    // not in specs

    // other
    void print();

private:
    string name;
    string plate_number;
    int num_people;
    Date check_in;
    Date check_out;
};

#endif