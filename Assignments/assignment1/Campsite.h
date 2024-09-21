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
    Campsite(int site_number, cat::Category category, string description, int maxPeople, double price_per_day);
    bool addCamper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out);

private:
    int site_number;
    cat::Category category;
    string description;
    int maxPeople;
    double price_per_day;
    Camper campers[MAX_ARRAY];
    int numCampers;
};

#endif