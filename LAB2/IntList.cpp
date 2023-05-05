#include <iostream>
#include "IntList.h"
using namespace std; 

//Default constructor that initializes dummyHead and dummyTail to null
IntList::IntList() {
    dummyHead = nullptr; 
    dummyTail = nullptr; 
}

//Destructor that deallocates memory for each node in the linked list after the program terminates
IntList::~IntList() {
    //Removes nodes in the list by calling the pop front function until the list is empty
    while(!empty()) { 
        pop_front(); 
    }
    //Initializes dummyHead and dummyTail to null so that a memory leak isn't caused
    dummyHead = nullptr; 
    dummyTail = nullptr; 
}

//Inserts a new node to the front of the linked list
void IntList::push_front(int value) {
    IntNode* newNode = new IntNode(value); //Allocates space in memory for a new node to be inserted in the list
    if(dummyHead == nullptr) { //Checks if the list is empty and sets both dummyHead and dummyTail to the new node if it is (Edge case)
        dummyHead = newNode; 
        dummyTail = newNode;
    } else { 
        dummyHead -> prev = newNode; 
        newNode -> next = dummyHead; 
        dummyHead = newNode; //Finally reassigns dummyHead to the new node so that the new node has been fully inserted in the front of the list
    }
}

//Removes the node in the front of the linked list
void IntList::pop_front() {
    if(dummyHead == nullptr) { //In this case, the list is already empty and there are no nodes to remove (Edge Case)
        return; 
    } else if(dummyHead == dummyTail) { //In this case, there is only one node in the list (Edge Case)
        delete dummyHead; 
        dummyHead = nullptr; //dummyHead and dummyTail have to be initialized to null since the only node in the list is removed
        dummyTail = nullptr; 
        return; 
    } else { //Removes the current head node 
        IntNode* tempNode = dummyHead -> next; 
        delete dummyHead;  
        dummyHead = tempNode; //Reassigns dummyHead to dummyHead's next which is stored in tempNode
    }
}

//Inserts a new node to the back of the linked list
void IntList::push_back(int value) { 
    IntNode* newNode = new IntNode(value); //Allocates space in memory for a new node to be inserted in the list
    if(dummyHead == nullptr) { //Checks if the list is empty and sets both dummyHead and dummyTail to the new node if it is (Edge case)
        dummyHead = newNode;
        dummyTail = newNode; 
    } else {
        dummyTail -> next = newNode; 
        newNode -> prev = dummyTail; 
        dummyTail = newNode; //Reassigns dummyTail to the new node so that the new node has been fully inserted in the end of the list
    }
}

//Removes the node in the back of the linked list
void IntList::pop_back() {
    if(dummyTail == nullptr) { //In this case, the list is already empty and there are no nodes to remove (Edge Case)
        return; 
    } else if(dummyHead == dummyTail) { //In this case, there is only one node in the list (Edge Case)
        delete dummyTail; 
        dummyHead = nullptr; //dummyHead and dummyTail are initialized to null since the only node in the list is removed
        dummyTail = nullptr; 
    } else { //Removes the current tail node
        IntNode* tempNode = dummyTail -> prev;
        delete dummyTail; 
        dummyTail = tempNode; //Reassigns dummy's tail to dummyTail's previous node which is stored in tempNode
    }
}

//Checks and returns true if the linked list is empty (null)
bool IntList::empty() const {
    if(dummyHead == nullptr) {
        return true; 
    } else {
        return false; 
    }
}

//Ostream operator that outputs to the stream all the values in the linked list
ostream & operator<<(ostream &out, const IntList &rhs) {
    if(rhs.dummyHead) {
        if(rhs.dummyHead -> next == nullptr) { //If there's only one node in the list, then only the value of that node is outputted
            out << rhs.dummyHead -> data; 
            return out; 
        } else {
            for(IntNode* i = rhs.dummyHead; i != nullptr; i = i -> next) { //Iterates through each node in the linked list
                out << (i -> data); //Outputs the data value of each node in the list as it goes through the loop
                if(i -> next != nullptr) { //Outputs a space between all values in the list EXCEPT after the last value outputted
                    out << " "; 
                }
            }
        }
    }
    return out; 
}

//Prints all of the values in the linked list in reverse order
void IntList::printReverse() const {
    //Starts from the tail node and iterates backwards through each node in the linked list (reverse)
    for(IntNode* reverseTail = dummyTail; reverseTail != nullptr; reverseTail = reverseTail -> prev) {
        cout << reverseTail -> data; //Ouputs the data value of each node in the list going backwards
        if(reverseTail -> prev != nullptr) { //Ouputs a space between all values in the list EXCEPT after the last value outputted
            cout << " "; 
        }
    }
}