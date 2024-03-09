#include "Playlist.hpp"
#include "../DataStructs/Node.hpp"
#include <iostream>

void Playlist::addSong(Song *song) {
    addLast(song);
}

void Playlist::playSong(int index) {
    if (index > size() || index < 0){
        std::cout << "SONG " << index << " NOT AVAILABLE\n";
        return;
    }
   currentlyPlaying = getFromIndex(index);
}

Node<Song*>* Playlist::getCurrentPlaying() {
    return currentlyPlaying;
}