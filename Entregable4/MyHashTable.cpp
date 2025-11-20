#include "MyHashTable.h"
#include <functional>
#include <vector>
#include <cstdlib>

MyHashTable::MyHashTable(){
    this->size=0;
    this->sizeA=601;
    this->tabla=new MyLinkedList[this->sizeA];
}

MyHashTable::~MyHashTable() {
    delete[] this->tabla;
    this->tabla = nullptr;
    this->size = 0;
    this->sizeA = 0;
}

int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    long long hashCode=static_cast<long long>(hashC);
    return static_cast<int>(llabs(hashCode) % this->sizeA);
}

bool MyHashTable::isEmpty() {
    return this->size == 0;
}

