#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
using std::cout;
using std::cerr;
using std::endl;

template <typename T>
class Node {
public:
    T data;
    Node<T> * next;
    Node<T> * previous;
    Node (T dataIn)
                : data(dataIn), next(nullptr), previous(nullptr) {
    }
};


template<typename T>
class NodeIterator {
  
private:
    
    Node<T>* current;
    
public:
    

    NodeIterator(Node<T>* currentIn)
        : current(currentIn) {        
    }

    T & operator*() {
        return current->data;
    }

    // TODO: complete the code for NodeIterator here
    void operator++() {
        current = current->next;
    }
    bool const operator==(NodeIterator &otherNodeIterator) {
        return current == otherNodeIterator.current;
    }
    bool const operator!=(NodeIterator &otherNodeIterator) {
        return current != otherNodeIterator.current;
    }
        
    
};

// do not edit below this line

#endif
