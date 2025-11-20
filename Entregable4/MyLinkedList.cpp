#include "MyLinkedList.h"
#include <stdexcept>

MyLinkedList::MyLinkedList() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

MyLinkedList::~MyLinkedList() {

}

int MyLinkedList::length() {
    return this->size;
}

bool MyLinkedList::isEmpty() {
    return this->size == 0;
}