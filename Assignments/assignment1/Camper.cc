#include "Camper.h"

Camper::Camper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out)
{
    this->name = name;
    this->plate_number = plate_number;
    this->num_people = num_people;
    this->check_in = check_in;
    this->check_out = check_out;
};

Camper::Camper()
{
    this->name = "dummy";
    this->plate_number = "dummy";
    this->num_people = 1;
    this->check_in = Date();
    this->check_out = Date();
};

Date Camper::getStartDate()
{
    return check_in;
};

Date Camper::getEndDate()
{
    return check_out;
};

string Camper::getName()
{
    return name;
};

void Camper::print()
{
    cout << "Name: " << name << endl;
    cout << "Plate Number: " << plate_number << endl;
    cout << "Number of People: " << num_people << endl;
    cout << "Check In: " << endl;
    check_in.print();
    cout << "Check Out: " << endl;
    check_out.print();
};