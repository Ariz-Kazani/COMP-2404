#include <iostream>
#include "Campground.h"
#include "defs.h"
#include "Campsite.h"

using namespace std;

Campground::Campground()
{
    numSites = 0;
};

void Campground::addCampsite(int site_number, cat::Category category, string description, int maxPeople, double price_per_day)
{
    if (numSites < MAX_ARRAY)
    {
        campSites[numSites] = Campsite(site_number, category, description, maxPeople, price_per_day);
        numSites++;
        cout << "Campsite added successfully" << endl;
    }
    else
    {
        cout << "Error: Campsite array is full" << endl;
    }
};

void Campground::removeCampsite(int site_number)
{
    int position = 0;
    if (campsiteExists(position, site_number))
    {
        removeSpace(position);
        numSites--;
        cout << "Campsite #" << site_number << " was successfully removed!" << endl;
    }
    else
    {
        cout << "Error: Campsite not found!";
    }
};

void Campground::addCamper(int site_number, const string &name, const string &plate_number, int num_people, Date check_in, Date check_out)
{
    int position = 0;
    if (campsiteExists(position, site_number))
    {
        if (campSites[position].addCamper(name, plate_number, num_people, check_in, check_out))
        {
            cout << "Successfully added camper to campsite #" << site_number << endl;
        }
        else
        {
            cout << "Error: invalid camper details or campsite is full" << endl;
        }
    }
    else
    {
        cout << "Error: Campsite not found!" << endl;
    }
};

void Campground::removeCamper(int site_number, const string &name)
{
    int position = 0;
    if (campsiteExists(position, site_number))
    {
        if (campSites[position].removeCamper(name))
        {
            cout << "Successfully removed camper from campsite #" << site_number << endl;
        }
        else
        {
            cout << "Error: Camper not found!" << endl;
        }
    }
    else
    {
        cout << "Error: Campsite not found!" << endl;
    }
};

void Campground::printCampsite()
{
    cout << "Displaying all campsites" << endl;
    for (int i = 0; i < numSites; i++)
    {
        campSites[i].print();
    }
};

void Campground::PrintCampers(int site_number)
{
    int position = 0;
    if (campsiteExists(position, site_number))
    {
        campSites[position].printCampers();
    }
    else
    {
        cout << "Error: Campsite not found!" << endl;
    }
};

void Campground::printCampers(Date &date)
{
    cout << "Displaying campers for date: " << endl;
    date.print();
    for (int i = 0; i < numSites; i++)
    {
        campSites[i].printCamper(date);
    }
};

void Campground::printCampsitesByCategory(cat::Category category)
{
    cout << "Displaying campsites by category: " << cat::categoryToString(category) << endl;
    for (int i = 0; i < numSites; i++)
    {
        if (campSites[i].getCategory() == category)
        {
            campSites[i].print();
        }
    }
};

/**
 * A function that checks if a campsite exists in the campsite array
 */
bool Campground::campsiteExists(int &position, int site_number)
{
    for (int i = 0; i < numSites; i++)
    {
        if (campSites[i].getSiteNum() == site_number)
        {
            position = i;
            return true;
        }
    }
    return false;
}

/**
 * A function that removes a campsite from the campsite array
 */
void Campground::removeSpace(int position)
{
    for (int i = position; i < numSites - 1; i++)
    {
        campSites[i] = campSites[i + 1];
    }
}