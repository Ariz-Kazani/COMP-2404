#include "Podify.h"

Podify::Podify()
{
    podcasts = new Array<Podcast *>();
}

Podify::~Podify()
{
    for (int i = podcasts->getSize() - 1; i >= 0; i--)
    {
        delete podcasts->get(i);
    }

    delete podcasts;
}

void Podify::addPodcast(Podcast *p)
{
    podcasts->add(p);
}

void Podify::addEpisode(const string &title, Episode *e)
{
    Podcast *p = nullptr;

    for (int i = 0; i < podcasts->getSize(); i++)
    {
        if (podcasts->get(i)->equals(title))
        {
            p = podcasts->get(i);
            break;
        }
    }

    if (p == nullptr)
    {
        return;
    }

    p->add(e);
}

const Array<Podcast *> &Podify::getPodcasts() const
{
    return *podcasts;
}

Podcast *Podify::getPodcast(int index) const
{
    return podcasts->get(index);
}

Podcast *Podify::getPodcast(const string &title) const
{
    for (int i = 0; i < podcasts->getSize(); i++)
    {
        if (podcasts->get(i)->equals(title))
        {
            return podcasts->get(i);
        }
    }

    cout << "Podcast not found" << endl;
    exit(1);
}

Episode *Podify::getEpisode(const Search &s, Array<Episode> &epArr) const
{
    for (int i = 0; i < podcasts->getSize(); i++)
    {
        Podcast *p = podcasts->get(i);
        for (int j = 0; j < p->getSize(); j++)
        {
            Episode *ep = p->get(j);
            if (s.matches(ep))
            {
                epArr.add(*ep);
            }
        }
    }

    cout << "Episode not found" << endl;
    exit(1);
}
