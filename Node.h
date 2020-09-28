//
// Created by Collin Stratton on 9/26/20.
//

#ifndef SINGLYLINKEDLIST_NODE_H
#define SINGLYLINKEDLIST_NODE_H


struct Node {
    int data;
    struct Node* next;
    Node() {
        data = 0;
        next = nullptr;
    }
    Node(int newData) {
        data = newData;
        next = nullptr;
    }
    Node(Node &n) {
        data = n.data;
        next = n.next;
    }
};


#endif //SINGLYLINKEDLIST_NODE_H
