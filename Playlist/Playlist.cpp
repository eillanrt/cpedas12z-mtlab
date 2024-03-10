#include "Playlist.hpp"

void Playlist::addSong(Song *song) {
    addLast(song);
}

void Playlist::playSong(int index) {
    if (index > size() - 1 || index < 0){
        currentlyPlaying = nullptr;
    }
    currentlyPlaying = getFromIndex(index);
}

Node<Song*> *Playlist::getCurrentPlaying() {
    return currentlyPlaying;
}

void Playlist::setCurrentlyPlaying(Node<Song*> *song) {
    currentlyPlaying = song;
}

void Playlist::stopPlaying() {
    setCurrentlyPlaying(nullptr);
}

void Playlist::prevSong() {
    if (currentlyPlaying == nullptr){
        currentlyPlaying = head;
        return;
    }

    Node<Song*> *prev = currentlyPlaying->prev;

    if (prev == nullptr){
        currentlyPlaying = tail;
    } else {
        currentlyPlaying = prev;
    }
}

void Playlist::nextSong() {
    if (currentlyPlaying == nullptr){
        currentlyPlaying = head;
        return;
    }
    Node<Song*> *next = currentlyPlaying->next;
    if (next == nullptr){
        currentlyPlaying = head;
    } else {
        currentlyPlaying = next;
    }
}
