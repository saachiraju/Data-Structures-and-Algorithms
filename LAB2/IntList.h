#ifndef INTLIST_H
#define INTLIST_H
#include <iostream> 
using namespace std; 

struct IntNode {
    int data;
    IntNode *prev;
    IntNode *next;
    IntNode(int data) : data(data), prev(0), next(0) {}
};

class IntList {
    public: 
        //Default constructor that initializes dummyHead and dummyTail to null
        IntList();

        //Destructor that deallocates memory for each node in the linked list after the program terminates
        ~IntList(); 

        //Inserts a new node to the front of the linked list
        void push_front(int value); 

        //Removes the node in the front of the linked list
        void pop_front(); 

        //Inserts a new node to the back of the linked list
        void push_back(int value); 

        //Removes the node in the back of the linked list
        void pop_back(); 

        //Checks and returns true if the list is empty
        bool empty() const; 

        //Ostream operator that outputs to the stream all the values in the linked list
        friend ostream & operator<<(ostream &out, const IntList &rhs); 

        //Prints all of the values in the linked list in reverse order
        void printReverse() const; 
    private: 
        IntNode* dummyHead; 
        IntNode* dummyTail; 

        //Copy constructor that is declared in private so that users can't make copies 
        IntList(const IntList &cpy) = delete; 
        
        //Copy assigment operator that is declared in private so that users can't make copies
        IntList& operator=(const IntList &cpy) = delete; 
}; 

#endif