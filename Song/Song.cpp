#include "Song.hpp"
#include <string>

Song::Song(std::string title, std::string artist, std::string albumName, std::string genre, int durationInSeconds, int releaseYear){
    this->title = title;
    this->artist = artist;
    this->albumName = albumName;
    this->genre = genre;
    this->durationInSeconds = durationInSeconds;
    this->releaseYear = releaseYear;
}

std::string Song::getTitle(){
    return title;
}

std::string Song::getArtist(){
    return artist;
}

std::string Song::getAlbumName(){
    return albumName;
}

std::string Song::getGenre(){
    return genre;
}

int Song::getDurationInSeconds(){
    return durationInSeconds;
}

int Song::getReleaseYear(){
    return releaseYear;
}