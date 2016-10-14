#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"

// TODO your code goes here:
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
    LinkedList ()
            : head(nullptr), tail(nullptr), count(0) {
    }
    void push_front(T dataIn) {
        Node<T>* newNode = new Node<T>(dataIn);
        if (count == 0) {
            head = newNode;
            tail = newNode;
            ++count;
        }
        else {
            Node<T>* prevHead = head;
            head->previous = newNode;
            head = newNode;
            newNode->next = prevHead;
            ++count;
        }
    }
    T const front() {
        return head->data;
    }
    void push_back(T dataIn) {
        Node<T>* newNode = new Node<T>(dataIn);
        if (count == 0) {
            head = newNode;
            tail = newNode;
            ++count;
        }
        else {
            Node<T>* prevTail = tail;
            tail->next = newNode;
            tail = newNode;
            newNode->previous = prevTail;
            ++count;
        }
    }
    T const back() {
        return tail->data;
    }
    int const size() {
        return count;
    }/*
    NodeIterator const begin() {
        return NodeIterator(head);
    }
    NodeIterator<T> const end() {
        NodeIterator nI = begin();
        for (int i = 0; i <= size(); ++i) {
            nI++;
        }
        return nI;
    }
    ~LinkedList() {
        NodeIterator nI = begin();
        for (int i = 0; i < size(); ++i) {
            delete nI*;
            nI++;
        }
    }*/

};



// do not edit below this line

#endif
