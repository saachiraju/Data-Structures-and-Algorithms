#include <iostream> 
#include "IntList.h"
using namespace std; 

int main() {
    //Creates object which automatically calls default constructor and is used to invoke the other member functions
    IntList listObject;

    //Unit testing the member functions of IntList
    listObject.push_front(5);

    listObject.pop_front(); 

    listObject.push_back(9); 

    cout << listObject; //Implicitly calls the ostream operator function 

    listObject.printReverse();
    
    listObject.pop_back(); 

    listObject.empty(); 

    cout << listObject; //Implicitly calls the ostream operator function 

    listObject.printReverse();
}