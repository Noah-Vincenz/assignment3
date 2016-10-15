#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>

// TODO your code goes here:
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
    LinkedList () //TODO: change constructor so it takes initiliser list
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
    }
    NodeIterator<T> begin() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        return *nI;
    }
    NodeIterator<T> end() {
        NodeIterator<T>* nI = *begin();
        for (int i = 0; i <= size(); ++i) {
            nI++;
        }
        return *nI;
    }/*
    ~LinkedList() {
        NodeIterator<T> nI = begin();
        NodeIterator<T>* nI2 = *nI;
        for (int i = 0; i < size(); ++i) {
            delete nI.getCurrentNode();
            nI2++;
        }
    }*/
    NodeIterator<T> insert (NodeIterator<T>* nI, T dataIn) { //inserts before current & returns iterator pointing to newElem
        NodeIterator<T> nI2 = *nI;
        Node<T>* newNode(dataIn);
        Node<T> beforeNew = nI2.getCurrentNode()->previous;
        Node<T> afterNew = nI2.getCurrentNode();
        nI++;
        beforeNew.next = newNode;
        afterNew.previous = newNode;
        *newNode->next = afterNew;
        *newNode->previous = beforeNew;
        count++;
        return nI;
    }
    NodeIterator<T> erase (NodeIterator<T>* nI) {
        NodeIterator<T> nI2 = *nI;
        Node<T> first = nI2.getCurrentNode()->previous;
        Node<T> second = nI2.getCurrentNode()->next;
        nI2.getCurrentNode()->previous = nullptr;
        nI2.getCurrentNode()->next = nullptr;
        nI++;
        *first.next = second;
        *second.previous = first;
        count--; //delete first and second???
        return nI;
    }
};



// do not edit below this line

#endif
