#ifndef CAMPGROUND_H
#define CAMPGROUND_H

#include <iostream>
#include <string>
#include "defs.h"
#include "Campsite.h"
#include "Category.h"

using namespace std;
using namespace cat;

class Campground
{
public:
    // constructors
    Campground::Campground();

    // setters
    void addCampsite(int site_number, Category category, string description, int maxPeople, double price_per_day);
    void removeCampsite(int site_number);
    void addCamper(int site_number, const string &name, const string &plate_number, int num_people, Date check_in, Date check_out);
    void removeCamper(int site_number, const string &name);

    // other
    void printCampsites();
    void printCampers(int site_number);
    void printCampers(Date &date);
    void printCampsitesByCategory(Category category);

private:
    Campsite campSites[MAX_ARRAY];
    int numSites;

    bool campsiteExists(int &position, int site_number); // this function is not part of the specifications
    void removeSpace(int position);
};

#endif