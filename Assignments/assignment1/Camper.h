#ifndef CAMPER_H
#define CAMPER_H

#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

class Camper
{
public:
    Camper::Camper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out);
    Camper::Camper();
    void print();

private:
    string name;
    string plate_number;
    int num_people;
    Date check_in;
    Date check_out;
};

#endif