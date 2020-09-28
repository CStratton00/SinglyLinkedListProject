//
// Created by Collin Stratton on 9/26/20.
//

#ifndef SINGLYLINKEDLIST_LINKEDLIST_H
#define SINGLYLINKEDLIST_LINKEDLIST_H

#include "Node.h"

using namespace std;

struct LinkedList {
private:
    Node* head;
public:
    LinkedList() {                                          // Starts the head of a linked list
        head = nullptr;
    }

    int Size() {                                            // returns the size of a linked list
        struct Node* temp = head;                           // creates a temp value at the head to traverse the list
        int size = 0;                                       // size variable to store the size of the array

        while(temp != nullptr) {                            // while loop to traverse the list and count how many items are in the list
            temp = temp->next;
            size++;
        }

        return size;                                        // return the size of the list
    }

    bool isEmpty() { return Size() != 0; }                  // returns if there is nothing in the linked list

    int First() {                                           // returns the first item in the list
        struct Node* temp = head;
        return temp->data;                                  // grabs the first set of data in the list and returns it
    }

    int Last() {                                            // returns the last item in the list
        struct Node* temp = head;
        while(temp->next != nullptr) { temp = temp->next; } // loop to find the last item in the list
        return temp->data;                                  // grabs the last set of data in the list and returns it
    }

    void InsertFront(int newData) {
        struct Node* newNode = new Node;                    // creates a new node in the heap

        newNode->data = newData;                            // sets the data in the node
        newNode->next = head;                               // sets the node to point to the next value in the list

        head = newNode;                                     // sets the head equal to the new node
    }

    void InsertEnd(int newData) {
        struct Node* newNode = new Node;
        struct Node* temp = head;

        newNode->data = newData;
        newNode->next = nullptr;                            // sets the node pointing to null

        while(temp->next != nullptr) { temp = temp->next; } // finds the last value in the list and stores the last position
        temp->next = newNode;                               // sets the last value to point to the new node
    }

    void InsertPos(int p, int newData) {
        struct Node* newNode = new Node;
        struct Node* prev = new Node;                       // creates a node previous in the heap
        struct Node* temp = head;

        int position = p;                                   // sets position to the inputted position

        newNode->data = newData;                            // sets data to the inputted data
        for(int i = 1; i < position; i++) {                 // traverses the function until insert position is found
            prev = temp;                                    // sets previous to temp
            temp = temp->next;                              // sets temp to the next node
        }
        prev->next = newNode;                               // sets previous to point to the new node
        newNode->next = temp;                               // sets the new node to point to the next node
    }

    void RemoveFirst() {                                    // removes the first item in the list
        struct Node* temp = head;
        head = temp->next;                                  // sets the head to the next item in the list
        delete(temp);                                       // deletes the value at the front
    }

    void RemoveLast() {                                     // removes the last item in the list
        struct Node* prev = new Node;
        struct Node* temp = head;
        while(temp->next != nullptr) {                      // loop to find the last item in the list
            prev = temp;                                    // sets previous to the current temp
            temp = temp->next;                              // sets temp to the next item in the list
        }
        prev->next = temp->next;                            // sets the previous value in the list to the value after the next
        delete(temp);                                       // deletes the last item in the list
    }

    void ReverseList() {                                    // reverse the items int he list
        struct Node *next = nullptr, *prev = nullptr;       // sets a next and prev Node values
        struct Node* temp = head;

        while(temp != nullptr) {                            // loops through the whole list
            next = temp->next;                              // sets the next value to the next item in the list
            temp->next = prev;                              // sets the next value in the list to the previous value in the list
            prev = temp;                                    // sets previous value in the list to the current value
            temp = next;                                    // sets the current value in the list to the next value
        }
        head = prev;                                        // sets the head to the previous value (or now the last item)
    }

    void Merge(LinkedList &l) {                             // merges two lists together
        struct Node* temp = head;
        while(temp->next != nullptr) {                      // loops to the end of the first list
            temp = temp->next;
        }
        temp->next = l.head;                                // connects the end of the first list to the head of the second list
    }

    void display() {
        struct Node* temp;
        temp = head;

        cout << "Data in Linked List: ";
        while(temp != nullptr) {                            // traverses the list until null
            cout << temp->data << " ";                      // couts data
            temp = temp->next;
        }
        cout << endl;
    }
};


#endif //SINGLYLINKEDLIST_LINKEDLIST_H
