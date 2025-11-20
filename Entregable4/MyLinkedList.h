#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct MyNodeLL
{
    string key;
    vector<string> value; // ahora guardamos lista de fechas
    MyNodeLL* next;

    MyNodeLL() {
        this->key = "";
        this->value = vector<string>(0,0);
        this->next = nullptr;
    }

    MyNodeLL(string key, vector<string> value) {
        this->key = key;
        this->value = value;
        this->next = nullptr;
    }

    MyNodeLL(string key, vector<string> value, MyNodeLL* next) {
        this->key = key;
        this->value = value;
        this->next = next;
    }

    ~MyNodeLL() {}
};

class MyLinkedList {
    public:  
        int size;
        MyNodeLL* head;
        MyNodeLL* tail;

        MyLinkedList();
        ~MyLinkedList();

        int length();
        bool isEmpty(); 

        
};

#endif
