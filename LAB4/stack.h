#ifndef Stack_h
#define Stack_h
#include <iostream>
#include <stdexcept>

using namespace std;

//Creates a template for type T since the array supports different data types
template <typename T>
class stack {
    private:
        T data[20]; //Initializing the array to the maximum number of elements that can be stored into the array 
        int size;
        const int MAX_SIZE = 20;
    public:
        //Function that creates an empty stack 
        stack() : size(0) {}
        void push(T val); //Function that populates the array by pushing values in the array
        void pop(); //Removes the last element from the stack
        void pop_two(); //Removes the last two elements from the stack
        T top(); //Returns the top element of the stack (last inserted element in the array)
        bool empty() const; //Returns true if the stack is empty (size is 0) and false otherwise
};

#endif

template<typename T> 
void stack<T>::push(T val) {
    //Try block that throws an overflow exception if the current size of the array is equal to the maximum size allowed (stack is full)
    if (size == MAX_SIZE) {
        throw overflow_error("Called push on full stack.");
    }
    data[size] = val; //Pushes back value 
    size++; //Increments the size of the array
}

template<typename T>
//Removes the last element from the stack
void stack<T>::pop() {
    //Throws an exception if the pop function is called to remove an element even though the stack is empty
    if(size == 0) {
        throw out_of_range("Called pop on empty stack."); 
    }
    //Decrementing the size removes the last element from the stack
    size--; 
}

template<typename T>
//Removes the last two elements from the stack
void stack<T>::pop_two() {
    //Out of range exceptions are thrown if the array is empty or the size is 1
    if(size == 0) {
        throw out_of_range("Called pop_two on empty stack."); 
    } else if(size == 1) {
        throw out_of_range("Called pop_two on a stack of size 1.");
    }
    //Calls previous pop function twice to delete last two elements
    pop(); 
    pop(); 
}

template<typename T> //Creates a template for type T val used in the function below
//Returns the top element of the stack (last inserted element in the array)
T stack<T>::top() {
    //Throws an underflow exception if the top function is called to return the top element even though the stack is empty
    if(size == 0) {
        throw underflow_error("Called top on empty stack."); 
    } 
    //Returns top of the stack (last element of the array is top of the stack)
    return data[size - 1]; 
}

template<typename T>
//Returns true if the stack is empty (size is 0) and false otherwise
bool stack<T>::empty() {
    if(size == 0) {
        return true;
    }
    return false; 
}