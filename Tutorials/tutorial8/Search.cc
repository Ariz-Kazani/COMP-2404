#include <Search.h>

bool H_search::matches(const Episode* ep) const {
    return ep->getHost() == host;
}

void H_search::print(ostream &ost) const {
    ost << "Host: " << host;
}

bool C_search::matches(const Episode* ep) const {
    return ep->getCategory() == category;
}

void C_search::print(ostream &ost) const {
    ost << "Category: " << category;
}

bool And_search::matches(const Episode* ep) const {
    return left->matches(ep) && right->matches(ep);
}

void And_search::print(ostream &ost) const {
    left->print(ost);
    ost << " AND ";
    right->print(ost);
}

bool HorC_search::matches(const Episode* ep) const {
    return ep->getHost() == host && ep->getCategory() == category;
}

void HorC_search::print(ostream &ost) const {
    ost << "Host: " << host << " AND Category: " << category;
}

ostream& operator<<(ostream& ost, const Search& search) {
    search.print(ost);
    return ost;
}