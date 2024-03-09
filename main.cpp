#include "./Playlist/Playlist.hpp"
#include "./Song/Song.hpp"
#include <iostream>
using namespace std;

void home();
void clear()
{
    system("cls");
}

void showSongDetails(Node<Song *> *song)
{
    cout << "TITLE: " << song->data->getTitle() << "\n"
         << "ARTIST: " << song->data->getArtist() << "\n"
         << "ALBUM: " << song->data->getAlbumName() << "\n"
         << "GENRE: " << song->data->getGenre() << "\n"
         << "DURATION: " << song->data->getDurationInSeconds() << "\n"
         << "RELEASE YEAR: " << song->data->getReleaseYear() << "\n";
}

void showSongs(Playlist &playlist)
{
    clear();
    Node<Song *> *currentSong = playlist.getHead();
    int count = 0;

    while (currentSong != nullptr)
    {
        cout << string(50, '-') << "\n";
        cout << "SONG #" << count << endl;
        showSongDetails(currentSong);
        currentSong = currentSong->next;
        count++;
        cout << "\n";
    }
    home();
}

void player(Playlist &playlist)
{
    clear();
    cin.ignore();
    Node<Song *> *playingSong = playlist.getCurrentPlaying();
    Node<Song *> *nextSong = playingSong->next == nullptr ? playlist.getHead() : playingSong->next;

    int action;

    cout << "NOW PLAYING "
         << playingSong->data->getTitle() << " - " << playingSong->data->getArtist() << "\n\n";

    cout << "NEXT SONG: " << nextSong->data->getTitle() << " - " << nextSong->data->getArtist() << "\n\n";

    cout << "Press 0 to play NEXT SONG\nPress 1 to play PREV SONG\nPress 2 to STOP PLAYING\n=> ";

    cin >> action;
    if (action == 0)
    {
        playlist.nextSong();
        player(playlist);
    }
    else if (action == 1)
    {
        playlist.prevSong();
        player(playlist);
    }
    else if (action == 2)
    {
        home();
    }
}

void home()
{
    clear();
    Playlist playlist;

    playlist.addSong(new Song("Love Story", "Taylor Swift", "Fearless", "Pop", 220, 2009));
    playlist.addSong(new Song("Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock", 354, 1975));
    playlist.addSong(new Song("Shape of You", "Ed Sheeran", "÷", "Pop", 233, 2017));
    playlist.addSong(new Song("Billie Jean", "Michael Jackson", "Thriller", "Pop", 292, 1982));
    playlist.addSong(new Song("Hotel California", "Eagles", "Hotel California", "Rock", 390, 1976));

    cout << "WHAT DO YOU WANT TO DO?\n"
         << endl;

    string actions[] = {
        "Show songs",
        "add song",
        "play song",
        "exit"};

    for (int i = 0; i < 4; i++)
    {
        cout << i << " => " << actions[i] << endl;
    }

    int choice;

    cout << "=> ";
    cin >> choice;

    if (choice == 0)
    {
        showSongs(playlist);
    }
    else if (choice == 1)
    {
        // string title, artist, album, genre;
        // int durationInSeconds, releaseYear;
        cout << "ADD SONG IMPLEMENT SOON" << endl;
    }
    else if (choice == 2)
    {
        cout << "\n\nWHICH SONG YOU WANT TO PLAY?\n"
             << endl;
        Node<Song *> *song = playlist.getHead();

        int count = 0;
        int songNumber;

        while (song != nullptr)
        {
            string title = song->data->getTitle();
            string artist = song->data->getArtist();

            cout << count << ": " << title << " - " << artist << endl;
            count++;
            song = song->next;
        }
        cout << "\nSONG NUMBER => ";
        cin >> songNumber;

        playlist.playSong(songNumber);

        player(playlist);
    }
}

int main()
{
    cout << " WELCOME " << endl;
    cout << "PRESS 1 TO CONTINUE" << endl;
    cout << "PRESS Any key TO EXIT" << endl;
    string res;
    cin >> res;

    if (res == "1")
        home();

    return 0;
}