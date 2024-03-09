#ifndef SONG_HPP
#define SONG_HPP
#include <string>

class Song {
private:
    std::string title;
    std::string artist;
    std::string albumName;
    std::string genre;
    int durationInSeconds;
    int releaseYear;

public:
    Song(std::string title, std::string artist, std::string albumName, std::string genre, int durationInSeconds, int releaseYear);
    std::string getTitle();
    std::string getArtist();
    std::string getAlbumName();
    std::string getGenre();
    int getDurationInSeconds();
    int getReleaseYear();
};

#endif