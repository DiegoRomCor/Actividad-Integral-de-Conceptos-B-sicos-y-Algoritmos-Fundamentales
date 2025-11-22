//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#ifndef LINKEDLISTHASH_H
#define LINKEDLISTHASH_H

#include <iostream>
#include <vector>
using namespace std;

struct NodeLinked
{
    string key;
    vector<string> value;
    NodeLinked* next;

    NodeLinked(string key, vector<string> value, NodeLinked* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }   

    NodeLinked(string key, vector<string> value) : NodeLinked(key, value, nullptr) {}

    ~NodeLinked() {}
};

class LinkedListHash {
    public:  
        int size;
        NodeLinked* head;
        NodeLinked* tail;

        // Complejidad: O(1)
        LinkedListHash();
        // Complejidad: O(n)
        ~LinkedListHash();
        // Complejidad: O(1)
        int length();
        // Complejidad: O(1)
        bool isEmpty();
        // Complejidad: O(n)
        vector<string> getAt(string key); //Regresa el valor asociado a esta llave
        // Complejidad: O(1)
        void insertFirst(string key, vector<string> value);
        // Complejidad: O(1)
        void removeFirst();
        // Complejidad: O(1)
        void removeLast();
        // Complejidad: O(n)
        void removeAt(string key);
        // Complejidad: O(n)
        void flush();
};

#endif