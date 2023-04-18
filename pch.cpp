//Lorrell Winfield 
//Assignment - 3 (Queue)
//17 APR 2023
//Queue.cpp 

#include "pch.h"
#include <iostream>
#include <ostream>
#include <iomanip>

using namespace std;

Queue::Queue() { //Intialize a queue
    front = nullptr;
    rear = nullptr;
    count = 0;
    }

Queue::~Queue() {
    while (!isEmpty()) { //Delete nodes until empty
        dequeue();
    }
}

bool Queue::isEmpty() const {
    return front == nullptr;
}

void Queue::enqueue(int value) {        //Create a new node with the given value
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = newNode;                //Set both front and rear to the new node
        rear = newNode;
    }
    else {
        rear->next = newNode;           //Add the new node to the rear of the queue
        rear = newNode;
    }
    count++;                            //Increment the count of nodes in the queue
}

int Queue::dequeue() {
    try {
        if (isEmpty()) {        //Try and catch error block
            throw runtime_error("Error: The Queue is EMPTY!");
        }
        int data = front->data; //Get the data of the front node
        Node* temp = front;     //Create a temporary pointer to the front node
        front = front->next;    //Move front to the next node
        delete temp;            //Delete the front node using the temporary pointer
        count--;                //Decrement the count of nodes in the queue

        return data;
    }
    catch (runtime_error& e) {
        cout << e.what() << endl; //Catch the error and print error message
    }
}


int Queue::peek() const {
    try {                     //Try and catch error block
        if (isEmpty()) {
            throw runtime_error("Error: The Queue is EMPTY!");
        }
        else {
            return front->data;
        }
    }
    catch (runtime_error& e) {
        cout << e.what() << endl; //Catch the error and print error message
    }
}

int Queue::size() const {
    return count;              //Return the count of nodes in the queue
}
    