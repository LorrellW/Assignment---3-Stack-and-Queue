//Lorrell Winfield 
//Assignment - 3 (Queue)
//17 APR 2023
//Queue.h

#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>

using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) {
            data = value;
            next = nullptr;
        }
    };
    Node* front;
    Node* rear;
    int count;

public:
    Queue();                 //default constructor to create an empty queue
    ~Queue();                //destructor to free the memory allocated by the queue
    void enqueue(int value); //adds a new element to the rear of the queue
    int dequeue();           // removes and returns the front element of the queue
    int peek() const;        //returns the value of the front element without removing it
    bool isEmpty() const;    //returns true if the queue is empty, false otherwise
    int size() const;        //returns the number of elements in the queue
};
