#include "Search.h"

ostream &operator<<(ostream &ost, const Search &s)
{
    s.print(ost);
    return ost;
}

bool H_Search::matches(const Episode *ep) const
{
    return ep->getHost() == host;
}

void H_Search::print(ostream &ost) const
{
    ost << host;
}

bool C_Search::matches(const Episode *ep) const
{
    return ep->getCategory() == category;
}

void C_Search::print(ostream &ost) const
{
    ost << category;
}

bool HorC_Search::matches(const Episode *ep) const
{
    return ep->getHost() == host || ep->getCategory() == category;
}

void HorC_Search::print(ostream &ost) const
{
    ost << "Host: " << host << " And Category: " << category;
}
