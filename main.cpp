#include "./Playlist/Playlist.hpp"
#include "./Song/Song.hpp"
#include <iostream>

int main() {
  Playlist playlist;
  playlist.addLast(new Song("Love Story", "Taylor Swift", "Fearless", "Pop", 220, 2009));
  playlist.addLast(new Song("Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock", 354, 1975));
  playlist.addLast(new Song("Shape of You", "Ed Sheeran", "÷", "Pop", 233, 2017));
  playlist.addLast(new Song("Billie Jean", "Michael Jackson", "Thriller", "Pop", 292, 1982));
  playlist.addLast(new Song("Hotel California", "Eagles", "Hotel California", "Rock", 390, 1976));
  std::cout << "TOTAL NUMBER SONGS: " << playlist.size() << std::endl;

  return 0;
}