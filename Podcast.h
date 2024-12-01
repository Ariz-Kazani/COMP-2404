#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>

#include "Episode.h"
#include "Array.h"

using namespace std;

class Podcast
{
    friend ostream &operator<<(ostream &ost, const Podcast &podcast);

public:
    Podcast(const string &title, const string &host);
    ~Podcast();
    bool equals(const string &title) const;
    Episode *get(int index) const;
    int getSize() const;
    void add(Episode *episode);
    void print(ostream &ost) const;
    void printWithEpisodes(ostream &ost) const;

private:
    string title;
    string host;
    Array<Episode *> *episodes;
};

#endif
