#ifndef CAMPSITE_H
#define CAMPSITE_H

#include <string>
#include "Category.h"
#include "Camper.h"
#include "defs.h"

using namespace std;

class Campsite
{
public:
    // constructor
    Campsite(int site_number, cat::Category category, string description, int maxPeople, double price_per_day);

    // setters
    bool addCamper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out);
    bool removeCamper(const string &name);

    // other
    void print();
    void printCampers();
    void printCamper(Date &date);

private:
    int site_number;
    cat::Category category;
    string description;
    int maxPeople;
    double price_per_day;
    Camper campers[MAX_ARRAY];
    int numCampers;

    // helper functions not a part of the assignment specifications
    bool getVacancy(int position, Date check_in, Date check_out); // not in specs
    bool bookingsNotClash(Date &endDate, Date &startDate);        // not in specs
    void makeSpace(int position);                                 // not in specs
    bool camperExists(int &position, const string &name);         // not in specs
    void removeSpace(int position);                               // not in specs
};

#endif