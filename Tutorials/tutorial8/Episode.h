#include <iostream>
#include <string>

using namespace std;

class Episode {

friend ostream& operator<<(ostream& ost, const Episode& episode){
    episode.print(ost);
    return ost;
}

public:
    Episode(string podcastTitle, string host, string episodeTitle, string category, string audio, string videoFile) : podcastTitle(podcastTitle), host(host), episodeTitle(episodeTitle), category(category), audio(audio), videoFile(videoFile) {}
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