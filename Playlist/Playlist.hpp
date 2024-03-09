#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include "../DataStructs/DoublyLinkedList.hpp"
#include "../DataStructs/Node.hpp"
#include "../Song/Song.hpp"

class Playlist : public DoublyLinkedList<Song*> {
    Node<Song*> *currentlyPlaying;
public:
    void addSong(Song *song);
    void playSong(int index);
    Node<Song*> *getCurrentPlaying();
};


#endif