#include "Podcast.h"

Podcast::Podcast(const string &title, const string &host) : title(title), host(host)
{
    episodes = new Array<Episode *>();
}

Podcast::~Podcast()
{
    // for (int i = episodes->getSize() - 1; i >= 0; i--)
    // {
    //     delete episodes->get(i);
    // }

    episodes->clear();

    delete episodes;
}

bool Podcast::equals(const string &title) const
{
    return this->title == title;
}

Episode *Podcast::get(int index) const
{
    if (index < 0 || index >= episodes->getSize())
    {
        exit(1);
    }
    return episodes->get(index);
}

int Podcast::getSize() const
{
    return episodes->getSize();
}

void Podcast::print(ostream &ost) const
{
    ost << "Title: " << title << endl;
    ost << "Host:  " << host << endl;
}

void Podcast::printWithEpisodes(ostream &ost) const
{
    print(ost);
    for (int i = 0; i < episodes->getSize(); i++)
    {
        ost << endl;
        ost << *episodes->get(i) << endl;
    }
}

void Podcast::add(Episode *episode)
{
    episodes->add(episode);
}

ostream &operator<<(ostream &ost, const Podcast &podcast)
{
    podcast.print(ost);
    return ost;
}