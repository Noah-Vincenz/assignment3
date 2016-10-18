#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <initializer_list>
#include <list>

// TODO your code goes here:
template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int count;
public:
    LinkedList (std::initializer_list<T> l) {
        head = nullptr;
        tail = nullptr;
        count = 0;
        auto itr = l.begin();
        for (auto i = 0; i < l.size(); ++i) {
            push_back(*itr);
            itr++;
        }
    }
    LinkedList ()
            : head(nullptr), tail(nullptr), count(0) {
    }
    void push_front(const T dataIn) {
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
    void push_back(const T dataIn) {
        Node<T>* newNode = new Node<T>(dataIn);
        if (count == 0) {
            head = newNode;
            tail = newNode;
            ++count;
            //delete newNode;
        }
        else {
            Node<T>* prevTail = tail;
            tail->next = newNode;
            tail = newNode;
            tail->previous = prevTail;
            ++count;
            //delete prevTail; //--
        }
    }
    T const back() {
        return tail->data;
    }
    int const size() {
        return count;
    }
    NodeIterator<T> begin() { // do not change
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        return *nI;
    }
    NodeIterator<T> end() { // do not change
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        for (int i = 0; i < size(); ++i) { //changed it from <= to <
            nI->operator++();
        }
        return *nI;
    }
    ~LinkedList() {
        NodeIterator<T>* nI = new NodeIterator<T>(head);
        for (int i = 0; i < size(); ++i) {
            delete nI->getCurrentNode();
            nI->operator++();
        }
    }
    NodeIterator<T> insert (NodeIterator<T> nI,const T dataIn) { //inserts before current & returns iterator pointing to newElem
        Node<T>* newNode = new Node<T>(dataIn);
        Node<T>* beforeNew = nI.getCurrentNode()->previous;
        Node<T>* afterNew = nI.getCurrentNode();
        beforeNew->next = newNode;
        afterNew->previous = newNode;
        newNode->next = afterNew;
        newNode->previous = beforeNew;
        nI.operator--();
        count++;
        return nI;
    }
    NodeIterator<T> erase (NodeIterator<T> nI) {
        Node<T>* current = nI.getCurrentNode();
        Node<T>* before = nI.getCurrentNode()->previous;
        Node<T>* after = nI.getCurrentNode()->next;
        before->next = after;
        after->previous = before;
        nI.operator++();
        current->previous = nullptr; //yes or no
        current->next = nullptr; //yes or no
        delete current;
        --count; //delete current's first and second???
        return nI;
    }
};
// do not edit below this line

#endif
