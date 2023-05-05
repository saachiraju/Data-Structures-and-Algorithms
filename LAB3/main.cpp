#include <iostream> 
#include <stdexcept>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std; 

//Function that creates and populates the vector
vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

template<typename T> //Creates a template for type T vector

//Function that returns the index of the smallest value in the vector
unsigned min_index(const vector<T> &vals, unsigned index) {
    unsigned minIndex = index; 

    for(unsigned i = index; i < vals.size(); ++i) { //Iterates through the vector, starting from index to the end of the vector
        if(vals.at(minIndex) >= vals.at(i)) { //Checks if a value in the vector is smaller than the value currently stored in minIndex
            minIndex = i; //Reassign minIndex to the new smallest index 
        }
    }

    return minIndex;
}

template<typename T> //Creates a template for type T vector

//Selection sort function that orders the values in the vector into ascending order
void selection_sort(vector<T> &vals) {
    unsigned int minIndex = 0;

    //Iterates through the vector and calls the minIndex function to find the index with the smallest vector
    for(unsigned i = 0; i < vals.size(); ++i) { 
        minIndex = min_index(vals, i); 

        T temp; 
        //Swaps the current element's position and the position of the new minimum value
        temp = vals.at(i); 
        vals.at(i) = vals.at(minIndex);
        vals.at(minIndex) = temp; 
    }
}

template<typename T> //Creates a template for type T vector

//Function returns the corresponding value for the passed in index position
T getElement(vector<T> vals, unsigned int index) {
    if(index >= vals.size() || index < 0) { //Checks if the index is out of range or not
        throw std::runtime_error("out of range exception occurred"); //Throw statement outputs error message if index is out of bounds
        cout << endl; 
    }
    return vals.at(index); 
}

int main() {

    //Part B
    srand(time(0));
    vector<char> vals = createVector();
    char curChar;
    int index;
    int numOfRuns = 10;
    while(--numOfRuns >= 0){
        try { //The operations listed below in the try block will run BUT will go to the catch block if the index is out of range 
            cout << "Enter a number: " << endl;
            cin >> index;
            curChar = getElement(vals,index);
            cout << "Element located at " << index << ": is " << curChar << endl;
        } 
        catch(const std::out_of_range& excpt) { //Catches the out of range exception and ouputs an error message
            cout << excpt.what() << endl; 
        }
    }
    return 0;
}
