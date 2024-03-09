#include "Playlist.hpp"
#include "../DataStructs/Node.hpp"

void Playlist::addSong(Song *song) {
    addLast(song);
}

Node<Song*>* Playlist::playSong(int index) {
    if (index > size() - 1 || index < 0){
        std::cout << "SONG " << index << " NOT AVAILABLE\n";
        return nullptr;
    }
   currentlyPlaying = getFromIndex(index);
    return currentlyPlaying;

}

Node<Song*>* Playlist::getCurrentPlaying() {
    return currentlyPlaying;
}

void Playlist::prevSong() {
    if (currentlyPlaying == nullptr){
        currentlyPlaying = head;
        return;
    }

    Node<Song*>* prev = currentlyPlaying->prev;

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
    Node<Song*>* next = currentlyPlaying->next;
    if (next == nullptr){
        currentlyPlaying = head;
    } else {
        currentlyPlaying = next;
    }
}
