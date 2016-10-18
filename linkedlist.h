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
        auto itr = l.begin();
        /*cout << l.size() << endl;
        cout << *l.begin() << endl; //2
        cout << *l.end() << endl; //2
         */
        for (auto i = 0; i < l.size(); ++i) {
            push_back(*itr);
            itr++;
        }
        cout << "This is the linked list's size: " << size() << endl;
        auto itr2 = begin();
        for (auto i = 0; i < size(); ++i) {
            cout << itr2.getCurrentNode()->data << endl;
            itr2.operator++();
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
        for (int i = 0; i <= size(); ++i) {
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
        Node<T> beforeNew = *nI.getCurrentNode()->previous;
        Node<T> afterNew = *nI.getCurrentNode();
        nI.operator++();
        beforeNew.next = newNode;
        afterNew.previous = newNode;
        *newNode->next = afterNew;
        *newNode->previous = beforeNew;
        count++;
        return nI;
    }
    NodeIterator<T> erase (NodeIterator<T> nI) {
        Node<T> before = *nI.getCurrentNode()->previous;
        Node<T> after = *nI.getCurrentNode()->next;
        nI.getCurrentNode()->previous = nullptr;
        nI.getCurrentNode()->next = nullptr;
        nI.operator++();
        *before.next = after;
        *after.previous = before;
        count--; //delete first and second???
        return nI;
    }
};



// do not edit below this line

#endif
