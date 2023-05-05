#include <iostream> 
#include "Playlist.h"
#include <string>

//Parameterized constructor of the PlaylistNode class that sets private data members to user inputted variables
PlaylistNode::PlaylistNode(const string& userID, const string& userSongName, const string& userArtistName, int userSongLength) {
    uniqueID = userID; 
    songName = userSongName; 
    artistName = userArtistName; 
    songLength = userSongLength; 
    nextNodePtr = nullptr; 
}

//InsertAfter function inserts a new node in the linked list
void PlaylistNode::InsertAfter(PlaylistNode* newNode) {
        PlaylistNode* tempNextVar = nullptr; 

        tempNextVar = nextNodePtr; 
        nextNodePtr = newNode; 
        newNode -> nextNodePtr = tempNextVar; 
}

//Sets the private next pointer to the passed in next pointer
void PlaylistNode::SetNext(PlaylistNode* next) {
    nextNodePtr = next;
}

//Accessor function that returns the ID
const string & PlaylistNode::GetID() const {
    return uniqueID; 
}

//Accessor function that returns the song name
const string & PlaylistNode::GetSongName() const {
    return songName; 
}

//Accessor function that returns the artists' name
const string & PlaylistNode::GetArtistName() const {
    return artistName; 
}

//Accessor function that returns the length of the song 
int PlaylistNode::GetSongLength() const {
    return songLength; 
}

//Accessor function that returns a pointer to the next node of a previous node in the linked list
PlaylistNode* PlaylistNode::GetNext() const {
    return nextNodePtr; 
}

//Prints contents of each node in the list
void PlaylistNode::PrintPlaylistNode() {
    cout << "Unique ID: " << uniqueID << endl; 
    cout << "Song Name: " << songName << endl; 
    cout << "Artist Name: " << artistName << endl; 
    cout << "Song Length (in seconds): " << songLength << endl; 
    cout << endl; 
}

//Parameterized constructor for the Playlist class that intializes the private variables
Playlist::Playlist(const string& userPlaylistTitle) {
    playlistTitle = userPlaylistTitle; 
    head = nullptr; //Initialize head and tail to null 
    tail = nullptr;
}

//addSong function adds a song inputted by the user into the linked list
void Playlist::addSong(const string &userID, const string& userSongName, const string& userArtistName, int userSongLength) {
    PlaylistNode* newNode = new PlaylistNode(userID, userSongName, userArtistName, userSongLength); //Creates additional space in memory for a new node
//If the list is empty then the head and tail pointers both point to the new node
    if(head == nullptr) {
        head = newNode; 
        tail = newNode; 
//If the list isn't empty the tail's next pointer will be reassigned to the new node
    } else {
        tail -> SetNext(newNode); 
        tail = newNode; //The tail pointer of the linked list is reassigned to the new node
    }
}

//Removes song from the linked list based on the song's userID that the user inputs
void Playlist::removeSong(const string& userID) {
    string removedSongName; 
//If the user inputted ID is the same as the head node's ID
    if(head -> GetID() == userID) {
//Creates a pointer that points to the head of the list to be used later
        PlaylistNode* tempHead = head; 
//Getting the name of the song that has been removed
        removedSongName = head -> GetSongName();
//Reassigning head to head's next node
        head = head -> GetNext(); 
        delete tempHead; 
        cout << "\"" << removedSongName << "\" " << "removed." << endl; 
        return;
//Else condition for if the user inputted ID is located in any other node besides for the head node
    } else {
//Stores head and head's next into pointers called prev and next
        PlaylistNode* prev = head;
        PlaylistNode* curr = head -> GetNext(); 
//For loop goes through each node in the linked list
        for(PlaylistNode* i = curr; i != nullptr; i = i -> GetNext()) {
//f each node's ID matches with the user inputted ID 
            if(curr -> GetID() == userID) {
                removedSongName = curr -> GetSongName(); 
//Sets the node previous to the one removed to the next node of the removed node
                prev -> SetNext(curr -> GetNext()); 
                delete curr; 
                cout << "\"" << removedSongName << "\" " << "removed." << endl; 
                cout << endl; 
                return;
            } 
//Increments the prev and curr pointers
            prev = curr; 
            curr = curr -> GetNext(); 
        }
    }

}

//changePosition function moves a node from its original position to the new position both inputted by the user
void Playlist::changePosition(int originalPosition, int newPosition) {
    PlaylistNode* currPosition = head; 
    int listSize = 0; 
    int counterVar = 1;
    //Counts each node to find the size of the linked list
    for(PlaylistNode* i = currPosition; i != nullptr; i = i -> GetNext()) {
        listSize++; 
    }
        if(newPosition < 1) { //If the user inputs an invalid value (< 1) then the node will move to position 1 (the head)
            newPosition = 1; 
//Otherwise if the user inputs an invalid value (> the size of the list) then the node will move to the tail
        } else if(newPosition > listSize) { 
            newPosition = listSize; 
    }

//For loop iterates through the linked list to locate the node at the new position inputted by the user
    PlaylistNode* newNode = head; 
    for(int i = 1; i < newPosition; ++i) {
        newNode = newNode -> GetNext(); 
    } 

//Moving the head node (at position 1) to the new position given by the user
    if(originalPosition == 1) {
        PlaylistNode* headNext = head -> GetNext(); 
        PlaylistNode* tempHead = head; 
        tempHead -> SetNext(newNode -> GetNext()); //Sets the head's next pointer to the new node's next pointer (ex: 3,4,8,5 --> 4,8,3,5)
        newNode -> SetNext(tempHead); //Assigns the value currently in the new position's next pointer to the head pointer
        head = headNext; //Reassigns the head pointer to the node that head's next pointer is pointing to
        cout << "\"" << tempHead -> GetSongName() << "\"" << " moved to position " << newPosition << endl; 
        cout << endl; 
        return;
    }

//Moving a node to the position of the head node
    if(newPosition == 1) {
        counterVar = 1;
        for(int i = 0; i < listSize; ++i) {
            if(counterVar == originalPosition) { //Locates the node in the linked list
                break;
            }
            currPosition = currPosition->GetNext(); 
            counterVar++;
        }

        PlaylistNode* prevNode = head; 
        PlaylistNode* temperNode = currPosition;
        
        // finds the node before the current position
        for(int i = 1; i < originalPosition - 1; ++i) {
            prevNode = prevNode -> GetNext(); 
        }
        // links the linked list in proper order
        prevNode->SetNext(currPosition->GetNext());
        temperNode->SetNext(head);
        // reassigns head to maintain contiunity
        head = temperNode;

        cout << "\"" << currPosition -> GetSongName() << "\"" << " moved to position " << newPosition << endl; 
        return;
        
    }

     // if previous conditions are not met
        PlaylistNode* prevNode = head;
        PlaylistNode* currentNode = head;
        PlaylistNode* prevNewPos = head;

        // these 3 for loops will set the nodes in their proper positions
        for(int i = 1; i < originalPosition; ++i) { 
            currentNode = currentNode->GetNext();
        }

        for(int i = 1; i < originalPosition - 1; ++i) {
            prevNode = prevNode->GetNext();
        }

        for(int i = 1; i < newPosition - 1; ++i) {
            prevNewPos = prevNewPos->GetNext();
        }

        // links the node before the original position node to node after the original position
        prevNode->SetNext(currentNode->GetNext());
        
        PlaylistNode* temp = currentNode;


        
        if(originalPosition > newPosition) {
            prevNewPos->SetNext(currentNode); // links node
            currentNode->SetNext(newNode); 
            cout << "\"" << currentNode -> GetSongName() << "\"" << " moved to position " << newPosition << endl;
        } 
        else if(newPosition > originalPosition) {
            currentNode = head;
            int i = 1;
            // while loop to find the node before the new located position
            while(i < newPosition - 1) {
                currentNode = currentNode->GetNext();
                ++i;
            }
            // inserts a node after newfound current node to create a chain
            currentNode->InsertAfter(temp);
            cout << "\"" << temp -> GetSongName() << "\"" << " moved to position " << newPosition << endl; 

    }


}

//Outputs all the songs by a specific user inputted artist from the linked list
void Playlist::outputArtist(const string& userArtistName) {
    int artistNameCounter = 1; 
    for(PlaylistNode* i = head; i != nullptr; i = i -> GetNext()) {
//If condition for if the current node in the linked list matches the user inputted artist name
        if(i -> GetArtistName() == userArtistName) { 
            cout << artistNameCounter << '.' << endl; 
            i -> PrintPlaylistNode(); 
        }
        artistNameCounter++; 
    }
}

//Computes the sum of the song length durations for each node in the linked list
int Playlist::totalTime() {
    int songLengthSum = 0; 
    for(PlaylistNode* i = head; i != nullptr; i = i -> GetNext()) {
        songLengthSum += i -> GetSongLength(); //Adds each song time length to the sum 
    }
    return songLengthSum; 
}

//Outputs the full playlist with all the nodes in the linked list
void Playlist::Print() const {
//If condition for if the list is empty (has no nodes)
    if(head == nullptr) {
        cout << "Playlist is empty" << endl;
        cout << endl; 
    }
//Else condition to output each node in a not empty linked list
    else {
        PlaylistNode* currNode = head; 
        int count = 1; 
//Outputs each node and calls the previously made PrintPlaylistNode function to output in the correct format
        while(currNode != nullptr) {
                cout << count << '.' << endl; 
                count++; 
                currNode -> PrintPlaylistNode();
                currNode = currNode -> GetNext(); //Moves to the next node to output each node in the linked list
        }   
    }
}

//Destructor that deallocates each node in the linked list after the program's done 
Playlist::~Playlist() {
    PlaylistNode* nextPtr = nullptr; 
    PlaylistNode* currPtr = head;
    if(currPtr == nullptr) {
        return;
    }
    do {
        nextPtr = currPtr->GetNext();
        delete currPtr;
        currPtr = nextPtr;
    } while(currPtr != nullptr);
    
    head = nullptr; //Initializes both head and tail to null so there aren't memory leaks
    tail = nullptr;
}