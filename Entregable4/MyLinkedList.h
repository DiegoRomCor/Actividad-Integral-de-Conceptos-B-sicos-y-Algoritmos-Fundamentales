// Diego Romero Corvera
// A01646496

#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <vector>
using namespace std;

struct MyNodeLL
{
    string key;
    vector<string> value;
    MyNodeLL* next;

    MyNodeLL(string key, vector<string> value, MyNodeLL* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }   

    MyNodeLL(string key, vector<string> value) : MyNodeLL(key, value, nullptr) {}

    ~MyNodeLL() {}
};

class MyLinkedList {
    public:  
        int size;
        MyNodeLL* head;
        MyNodeLL* tail;

        // Complejidad: O(1)
        MyLinkedList();
        // Complejidad: O(n)
        ~MyLinkedList();
        // Complejidad: O(1)
        int length();
        // Complejidad: O(1)
        bool isEmpty();
        // Complejidad: O(1)
        vector<string> first();
        // Complejidad: O(1)
        vector<string> last();
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