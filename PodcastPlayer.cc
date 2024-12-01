#include "PodcastPlayer.h"

void AudioPlayer::play(const Episode &m, ostream &ost)
{
    ost << m.getAudio() << endl;
}

void VideoPlayer::play(const Episode &m, ostream &ost)
{
    ost << m.getAudio() << endl;
    string fileName = m.getVideoFile();
    ifstream infile(fileName);

    if (!infile)
    {
        ost << "ERROR FILE NOT FOUND" << endl;
        return;
    }

    string line;

    while (getline(infile, line))
    {
        ost << line << endl;
    }

    infile.close();
}