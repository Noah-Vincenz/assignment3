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
    LinkedList (std::initializer_list<T> l) {
        head = *l.begin();
        tail = *l.end();
        count = l.size();
        NodeIterator<T> * nI = new NodeIterator<T>(*l.begin());
        for (int i = 1; i < l.size(); ++i) {
            push_back(nI->getCurrentNode());
            nI->operator++();
        }
    }
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
            head->next = prevHead;
            ++count;
            //delete prevHead; //--
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
            //delete newNode;
        }
        else {
            Node<T>* prevTail = tail;
            //cout << "This is prevTail: " << prevTail->data << endl;
            tail->next = newNode;
            tail = newNode;
            //cout << "This is newTail: " << tail->data << endl;
            tail->previous = prevTail;
            ++count;
            //cout << endl;
            //delete prevTail; //--
        }
    }
    T const back() {
        return tail->data;
    }
    int const size() {
        return count;
    }/* //_______version1
    NodeIterator<T> begin() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        return *nI;
    }
    NodeIterator<T> end() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        for (int i = 0; i <= size(); ++i) {
            nI++;
        }
        return *nI;
    }
    ~LinkedList() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        NodeIterator<T> nI2 = *nI;
        for (int i = 0; i < size(); ++i) {
            delete nI2.getCurrentNode();
            nI++;
        }
        //delete nI; //--
        //delete nI2; //--
    }
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
    }*/ //version____2
    NodeIterator<T> begin() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        return *nI;
    }
    NodeIterator<T> end() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        for (int i = 0; i <= size(); ++i) {
            nI->operator++();
        }
        return *nI;
    }/*
    ~LinkedList() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        NodeIterator<T> nI2 = *nI;
        for (int i = 0; i < size(); ++i) {
            delete nI2.getCurrentNode();
            nI++;
        }
        //delete nI; //--
        //delete nI2; //--
    }*/
    NodeIterator<T> insert (NodeIterator<T> nI, T dataIn) { //inserts before current & returns iterator pointing to newElem
        NodeIterator<T> nI2 = *nI;
        Node<T>* newNode(dataIn);
        Node<T> beforeNew = nI2.getCurrentNode()->previous;
        Node<T> afterNew = nI2.getCurrentNode();
        *nI++;
        beforeNew.next = newNode;
        afterNew.previous = newNode;
        *newNode->next = afterNew;
        *newNode->previous = beforeNew;
        count++;
        return nI;
    }
    NodeIterator<T> erase (NodeIterator<T> nI) {
        NodeIterator<T> nI2 = *nI;
        Node<T> before = nI.getCurrentNode()->previous;
        Node<T> after = nI.getCurrentNode()->next;
        nI2.getCurrentNode()->previous = nullptr;
        nI2.getCurrentNode()->next = nullptr;
        nI.operator++();
        *before.next = after;
        *after.previous = before;
        count--; //delete first and second???
        return nI;
    }
};



// do not edit below this line

#endif
