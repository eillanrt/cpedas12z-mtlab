#include "./Playlist/Playlist.hpp"
#include <iostream>
using namespace std;

Playlist playlist;

void home();
void clear()
{
    system("cls");
}

void showSongDetails(Node<Song*> *song)
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

    Node<Song*> *currentSong = playlist.getHead();
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
    Node<Song*> *playingSong = playlist.getCurrentPlaying();

   if (playingSong == nullptr) {
      cout << "\nSONG NOT AVAILABLE!\n";
      home();
      return;
   }

    Node<Song*> *nextSong = playingSong->next == nullptr ? playlist.getHead() : playingSong->next;

    int action;

    cout << "NOW PLAYING: "
         << "\n\n";
    showSongDetails(playingSong);

    cout << "\nNEXT SONG: " << nextSong->data->getTitle() << " - " << nextSong->data->getArtist() << "\n\n";

    cout << "Press 0 to play NEXT SONG\nPress 1 to play PREV SONG\nPress 2 to STOP PLAYING\n=> ";

    cin >> action;
    if (action == 0)
    {
        playlist.nextSong();
    }
    else if (action == 1)
    {
        playlist.prevSong();
    }
    else if (action == 2)
    {
        clear();
        playlist.stopPlaying();
        home();
    } else {
        cout << "INVALID PROMPT" << endl;
    }
    player(playlist);
}

void home()
{
    cout << string(50, '=')
         << "\nWHAT DO YOU WANT TO DO?\n"
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
        clear();
        showSongs(playlist);
    }
    else if (choice == 1)
    {
        clear();
        cin.ignore();
        string title, artist, albumName, genre;
        int durationInSeconds, releaseYear;

        cout << "ENTER SONG DETAILS\n\n";

        cout << "TITLE: ";
        getline(cin, title);

        cout << "ARTIST: ";
        getline(cin, artist);

        cout << "ALBUM: ";
        getline(cin, albumName);

        cout << "GENRE: ";
        getline(cin, genre);

        cout << "DURATION: ";
        cin >> durationInSeconds;

        cout << "RELEASE YEAR: ";
        cin >> releaseYear;

        cin.ignore();

        Song *song = new Song(title, artist, albumName, genre, durationInSeconds, releaseYear);
        playlist.addSong(song);

        cout << "\nSONG ADDED SUCCESSFULLY\n";

        home();
    }
    else if (choice == 2)
    {
        clear();
        cout << "\n\nWHICH SONG YOU WANT TO PLAY?\n"
             << endl;
        Node<Song*> *song = playlist.getHead();

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
    } else if (choice == 3) {
        exit(0);
    } else {
        cout << "INVALID PROMPT!" << endl;
        home();
    }

}

void seedPlaylist()
{
    playlist.addSong(new Song("Love Story", "Taylor Swift", "Fearless", "Pop", 220, 2009));
    playlist.addSong(new Song("Bohemian Rhapsody", "Queen", "A Night at the Opera", "Rock", 354, 1975));
    playlist.addSong(new Song("Shape of You", "Ed Sheeran", "÷", "Pop", 233, 2017));
    playlist.addSong(new Song("Billie Jean", "Michael Jackson", "Thriller", "Pop", 292, 1982));
    playlist.addSong(new Song("Hotel California", "Eagles", "Hotel California", "Rock", 390, 1976));
}

int main()
{
    seedPlaylist();
    cout << " WELCOME " << endl;
    //  cout << "PRESS 1 TO CONTINUE" << endl;
    //  cout << "PRESS Any key TO EXIT" << endl;
    /*
    string res;
    cin >> res;

    if (res == "1")
    {
        home();
        ` clear();
    }
    else
    {
        exit(0);
    }
    */

    home();

    return 0;
}
