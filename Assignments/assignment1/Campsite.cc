#include <string>
#include "Category.h"
#include "Campsite.h"
#include "Camper.h"
#include "defs.h"

using namespace std;

Campsite::Campsite(int site_number, cat::Category category, string description, int maxPeople, double price_per_day)
{
    this->site_number = site_number;
    this->category = category;
    this->description = description;
    this->maxPeople = maxPeople < 1 ? 1 : maxPeople;
    this->price_per_day = price_per_day <= 0 ? 1 : price_per_day;
    this->numCampers = 0;
};

bool Campsite::addCamper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out)
{
    if (numCampers < MAX_ARRAY || num_people <= maxPeople)
    {
        int position;
        if (getVacancy(position, check_in, check_out))
        {
            makeSpace(position);
            campers[position] = Camper(name, plate_number, num_people, check_in, check_out);
            numCampers++;
            return true;
        }
    }
    return false;
};

bool Campsite::removeCamper(const string &name)
{
    int position;
    if (camperExists(position, name))
    {
        removeSpace(position);
        numCampers--;
        return true;
    }
    return false;
};

/**
 * A function that checks if a campsite can be booked for a given date range
 * returns true if the campsite is available for the given date range
 * position is the index of the campsite in the campers Sarray
 */
bool Campsite::getVacancy(int position, Date check_in, Date check_out)
{
    Date nextCamperSD = campers[0].getStartDate();
    if (numCampers == 0 || bookingsNotClash(check_out, nextCamperSD))
    {
        position = 0;
        return true;
    }
    for (int i = 0; i < numCampers - 2; i++)
    {
        Date prevCamperED = campers[i].getEndDate();
        if (!bookingsNotClash(prevCamperED, check_in))
        {
            continue;
        }
        Date nextCamperSD = campers[i + 1].getEndDate();
        if (bookingsNotClash(check_out, nextCamperSD))
        {
            position = i;
            return true;
        }
        else
        {
            return false;
        }
    }
    Date prevCamperED = campers[numCampers - 1].getEndDate();
    if (bookingsNotClash(check_in, prevCamperED))
    {
        position = numCampers;
        return true;
    }
    return false;
};

/**
 * A function that checks if two dates do not clash
 * returns true if the dates do not clash
 */
bool Campsite::bookingsNotClash(Date &endDate, Date &startDate)
{
    return endDate.lessThan(startDate) || endDate.equals(startDate);
};

/**
 * A function that makes space in the campers array
 */
void Campsite::makeSpace(int position)
{
    for (int i = numCampers; i > position; i--)
    {
        campers[i] = campers[i - 1];
    }
};

/**
 * A function that checks if a camper exists in the campers array
 */
bool Campsite::camperExists(int &position, const string &name)
{
    for (int i = 0; i < numCampers; i++)
    {
        if (campers[i].getName() == name)
        {
            return true;
        }
    }
    return false;
};

/**
 * A function that removes space in the campers array
 */
void Campsite::removeSpace(int position)
{
    for (int i = position; i < numCampers - 1; i++)
    {
        campers[i] = campers[i + 1];
    }
};