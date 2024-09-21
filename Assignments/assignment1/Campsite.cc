#include <string>
#include "Category.h"
#include "Campsite.h"
#include "Camper.h"

using namespace std;

Campsite::Campsite(int site_number, cat::Category category, string description, int maxPeople, double price_per_day)
{
    Campsite::site_number = site_number;
    Campsite::category = category;
    Campsite::description = description;
    Campsite::maxPeople = maxPeople < 1 ? 1 : maxPeople;
    Campsite::price_per_day = price_per_day <= 0 ? 1 : price_per_day;
    Campsite::numCampers = 0;
}

bool Campsite::addCamper(const string &name, const string &plate_number, int num_people, Date check_in, Date check_out)
{
    if (numCampers < MAX_ARRAY)
    {
        campers[numCampers] = Camper(name, plate_number, num_people, check_in, check_out);
        numCampers++;
        return true;
    }
    return false;
}