#ifndef PODIFY_H
#define PODIFY_H

#include <iostream>
#include <string>
#include "Array.h"
#include "Podcast.h"
#include "Search.h"

using namespace std;

class Podify
{
public:
    Podify();
    ~Podify();
    void addPodcast(Podcast *p);
    void addEpisode(Episode *e, const string &title);
    const Array<Podcast *> &getPodcasts() const;
    Podcast *getPodcast(int index) const;
    Podcast *getPodcast(const string &title) const;
    Episode *getEpisodes(const Search &s, Array<Episode *> &epArr) const;

private:
    Array<Podcast *> *podcasts;
};

#endif