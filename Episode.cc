#include "Episode.h"

ostream &operator<<(ostream &ost, const Episode &episode)
{
    episode.print(ost);
    return ost;
}

string Episode::getPodcastTitle() const
{
    return podcastTitle;
}

string Episode::getHost() const
{
    return host;
}

string Episode::getEpisodeTitle() const
{
    return episodeTitle;
}

string Episode::getCategory() const
{
    return category;
}

string Episode::getAudio() const
{
    return audio;
}

string Episode::getVideoFile() const
{
    return videoFile;
}

void Episode::print(ostream &ost) const
{
    ost << "Podcast Title: " << podcastTitle << endl;
    ost << "Host:          " << host << endl;
    ost << "Episode Title: " << episodeTitle << endl;
    ost << "Category:      " << category << endl;
    ost << "Audio:         " << audio << endl;
    ost << "Video File:    " << videoFile << endl;
}
