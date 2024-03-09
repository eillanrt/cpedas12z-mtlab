#include "Playlist.hpp"
#include "../DataStructs/Node.hpp"
#include <iostream>

void Playlist::addSong(Song *song) {
    addLast(song);
}

void Playlist::playSong(int index) {
    if (index > size() - 1 || index < 0){
        std::cout << "SONG " << index << " NOT AVAILABLE\n";
        return;
    }
   currentlyPlaying = getFromIndex(index);
}

Node<Song*>* Playlist::getCurrentPlaying() {
    return currentlyPlaying;
}

void Playlist::nextSong() {
    Node<Song*>* nextSong = currentlyPlaying->next;
    if (currentlyPlaying == nullptr){
        currentlyPlaying = head;
        return;
    }
    currentlyPlaying = nextSong;
}

