#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include "../DataStructs/DoublyLinkedList.hpp"
#include "../Song/Song.hpp"

class Playlist : public DoublyLinkedList<Song*> {
public:
    void addSong(Song *song);
};


#endif