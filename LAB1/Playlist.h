#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <iostream> 
using namespace std; 

class PlaylistNode {
    public: 
        //Default Constructor intializes private data members 
        PlaylistNode() : uniqueID("none"), songName("none"), artistName("none"), songLength(0), nextNodePtr(nullptr) {}

        //Parameterized constructor sets user inputted variables to private data members 
        PlaylistNode(const string& userID, const string& userSongName, const string& userArtistName, int userSongLength); 

        //Insert After function inserts a value after a specified node in the list
        void InsertAfter(PlaylistNode* newNode); 

        //Moves pointer to the next node so that it can be accessed
        void SetNext(PlaylistNode* next); 

        //Accessor functions
        const string & GetID() const; 
        const string & GetSongName() const; 
        const string & GetArtistName() const; 
        int GetSongLength() const;
        PlaylistNode* GetNext() const; 

        //Prints each node and relays ID, song name, artist name, and song length
        void PrintPlaylistNode(); 

    private: 
        string uniqueID; 
        string songName;
        string artistName;
        int songLength; 
        PlaylistNode* nextNodePtr; 
};

class Playlist {
    public: 
        //Default constructor initializes private data members
        Playlist() : head(nullptr), tail(nullptr)  {}

        //Parameterized constructor intializes the title of the playlist inputted by the user
        Playlist(const string& playlistTitle); 

        //addSong function adds a song inputted by the user into the linked list
        void addSong(const string& userID, const string& userSongName, const string& userArtistName, int userSongLength); 

        //Removes song from the linked list based on the song's userID that the user inputs
        void removeSong(const string& userID); 

        //changePosition function moves a node from its original position to the new position both inputted by the user
        void changePosition(int originalPosition, int newPosition); 

        //Outputs all the songs by a specific user inputted artist from the linked list
        void outputArtist(const string& userArtistName); 

        //Computes the sum of the song length durations for each node in the linked list
        int totalTime(); 
        
        //Outputs the full playlist with all the nodes in the linked list
        void Print() const;

        //Destructor that deallocates each node in the linked list after the program's done 
        ~Playlist(); 

        

    private: 
        PlaylistNode* head; 
        PlaylistNode* tail; 
        string playlistTitle; 
        Playlist(const Playlist& copy) = delete; //Copy constructor that is defined in private so users can't make copies
        Playlist& operator=(const Playlist& copy) = delete; //Copy assignment operator that is defined in private so users can't make copies
}; 

#endif