#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H

#include "MyLinkedList.h"
#include <string>

using namespace std;

class MyHashTable{
    public:
       MyLinkedList* tabla; 
       int size; 
       int sizeA; 

       void rehashing();
       int getPos(string key);

       MyHashTable();  
       ~MyHashTable();
       bool isEmpty();

       
};
#endif
