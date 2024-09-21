#include <iostream>
#include <string>
#include "Camper.h"
#include "Date.h"

using namespace std;

Camper::Camper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out)
{
    Camper::name = name;
    Camper::plate_number = plate_number;
    Camper::num_people = num_people;
    Camper::check_in = check_in;
    Camper::check_out = check_out;
}

Camper::Camper()
{
    Camper::name = "dummy";
    Camper::plate_number = "dummy";
    Camper::num_people = 1;
    Camper::check_in = Date();
    Camper::check_out = Date();
}

void Camper::print()
{
    cout << "Name: " << name << endl;
    cout << "Plate Number: " << plate_number << endl;
    cout << "Number of People: " << num_people << endl;
    cout << "Check In: " << endl;
    check_in.print();
    cout << "Check Out: " << endl;
    check_out.print();
}