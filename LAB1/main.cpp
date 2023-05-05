#include <iostream> 
#include "Playlist.h"
using namespace std;

//Full menu options relayed to the user 
void PrintMenu(string userPlaylistTitle) {
    cout << userPlaylistTitle << " PLAYLIST MENU" << endl; 
    cout << "a - Add song" << endl; 
    cout << "d - Remove song" << endl; 
    cout << "c - Change position of song" << endl; 
    cout << "s - Output songs by specific artist" << endl; 
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl; 
    cout << "q - Quit" << endl; 
    cout << endl; 
    cout << "Choose an option:" << endl; 
}

int main() {
    string userID; 
    string userSongName; 
    string userArtistName; 
    int userSongLength; 

    string userPlaylistTitle;
    cout << "Enter playlist's title:" << endl; 
    getline(cin, userPlaylistTitle);
    Playlist playlistTitle(userPlaylistTitle); //Object created with the playlist title that goes to parameterized constructor

    char userMenuChoice; 
    cin >> userMenuChoice;
    cin.ignore();

//Do while loop to create if conditions for each menu option that the user inputs
    do {
        if(userMenuChoice == 'a') { //Menu choice for addSong function
            cout << "ADD SONG" << endl; 
            cout << "Enter song's unique ID:" << endl; 
            getline(cin, userID);
            cout << "Enter song's name:" << endl; 
            getline(cin, userSongName); 
            cout << "Enter artist's name:" << endl; 
            getline(cin, userArtistName); 
            cout << "Enter song's length (in seconds):" << endl; 
            cout << endl; 
            cin >> userSongLength; 
            cin.ignore();

            playlistTitle.addSong(userID, userSongName, userArtistName, userSongLength);
        } else if(userMenuChoice == 'd') { //Menu choice for removeSong function
            cout << "REMOVE SONG" << endl; 
            cout << "Enter song's unique ID:" << endl; 
            getline(cin, userID); 
            playlistTitle.removeSong(userID); 
        } else if(userMenuChoice == 'c') { //Menu choice for changePosition function
            int originalPosition; 
            int newPosition; 
            cout << "CHANGE POSITION OF SONG" << endl; 
            cout << "Enter song's current position:" << endl; 
            cin >> originalPosition; 
            cout << "Enter new position for song:" << endl; 
            cin >> newPosition; 
            playlistTitle.changePosition(originalPosition, newPosition); 
        } else if(userMenuChoice == 's') { //Menu choice for outputArtist function
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl; 
            cout << "Enter artist's name:" << endl;  
            cout << endl; 
            getline(cin, userArtistName);
            playlistTitle.outputArtist(userArtistName); 
        } else if(userMenuChoice == 'o') { //Menu choice for Print function
            cout << userPlaylistTitle << " - OUTPUT FULL PLAYLIST" << endl;
            playlistTitle.Print();
        } else if(userMenuChoice == 't') { //Menu choice for totalTime function
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl; 
            cout << "Total time: " << playlistTitle.totalTime() << " seconds" << endl; 
            cout << endl; 
        } else if(userMenuChoice == 'q') { //Menu choice for quitting the playlist
            cout << endl; 
        }
        cin >> userMenuChoice;
        cin.ignore();
        PrintMenu(userPlaylistTitle); 
    } while(userMenuChoice != 'q'); //Program continues until the user inputs the 'q' menu option
}