#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;

class Episode
{
    friend ostream &operator<<(ostream &ost, const Episode &episode);

public:
    Episode(const string &podcastTitle, const string &host, const string &episodeTitle, const string &category, const string &audio, const string &videoFile) : podcastTitle(podcastTitle), host(host), episodeTitle(episodeTitle), category(category), audio(audio), videoFile(videoFile) {}
    string getPodcastTitle() const;
    string getHost() const;
    string getEpisodeTitle() const;
    string getCategory() const;
    string getAudio() const;
    string getVideoFile() const;
    void print(ostream &ost) const;

private:
    string podcastTitle;
    string host;
    string episodeTitle;
    string category;
    string audio;
    string videoFile;
};

#endif