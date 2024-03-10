#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP
#include "../DataStructs/DoublyLinkedList.hpp"
#include "../DataStructs/Node.hpp"
#include "../Song/Song.hpp"

class Playlist : public DoublyLinkedList<Song*> {
private:
    Node<Song*> *currentlyPlaying = nullptr;
public:
    void addSong(Song *song);
    Node<Song*> *playSong(int index);
    Node<Song*> *getCurrentPlaying();
    void prevSong();
    void nextSong();
};


#endif
