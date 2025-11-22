//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#include "LinkedListHash.h"
#include <iostream>

using namespace std;

// Complejidad: O(1)
LinkedListHash::LinkedListHash() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

// Complejidad: O(n)
LinkedListHash::~LinkedListHash() {
    // Obtenido parcialmente de: https://www.youtube.com/watch?v=kq4cduYutI8
    // En este video mas que nada me apoye de la logica para eliminar nodos.
    this->flush();
}

// Complejidad: O(1)
int LinkedListHash::length() {
    return this->size;
}

// Complejidad: O(1)
bool LinkedListHash::isEmpty() {
    return this->size == 0;
}

// Complejidad: O(1)
void LinkedListHash::insertFirst(string key, vector<string> value) {
    NodeLinked* nuevo = new NodeLinked(key,value,this->head);
    this->head = nuevo;
    if(this->size == 0) {
        this->tail = nuevo;
    }
    this->size++;
}

// Complejidad: O(n)
vector<string> LinkedListHash::getAt(string key) {
    NodeLinked* actualent = this->head;
    while(actualent) {
        if(actualent->key == key) {
            return actualent->value;
        } else {
            actualent = actualent->next;
        }
    }
    throw invalid_argument("No se encuentra la Key " + key);
}

// Complejidad: O(1)
void LinkedListHash::removeFirst() {
    if(this->isEmpty()) {
        throw invalid_argument("No se puede eliminar el primer elemento de una lista vacia");
    }

    NodeLinked* auxiliar = this->head;
    this->head = this->head->next;
    delete auxiliar;
    this->size--;

    if(this->size == 0) {
        this->tail = nullptr;
        this->head = nullptr;
    }
}

// Complejidad: O(1)
void LinkedListHash::removeLast() {
    if(this->isEmpty()) {
        throw invalid_argument("No se puede eliminar el último elemento de una lista vacia");
    }

    if(this->size == 1) {
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
        return;
    }

    NodeLinked* auxiliar = this->head;
    while(auxiliar->next != this->tail) {
        auxiliar = auxiliar->next;
    }
    delete this->tail;
    this->tail = auxiliar;
    this->tail->next = nullptr;
    this->size--;
}

// Complejidad: O(n)
void LinkedListHash::removeAt(string key) {
    if(this->isEmpty()) {
        throw invalid_argument("No se puede eliminar de una lista vacia");
    }

    if(this->head->key == key) {
        this->removeFirst();
        return;
    }

    if(this->tail->key == key) {
        this->removeLast();
        return;
    }

    NodeLinked* padre = this->head;
    NodeLinked* actual = this->head->next;

    while(actual) {
        if(actual->key == key) {
            padre->next = actual->next;
            if(actual == this->tail) {
                this->tail = padre;
            }
            delete actual;
            this->size--;
            return;
        }
        padre = actual;
        actual = actual->next;
    }

    throw invalid_argument("No se encuentra la Key " + key);
}

// Complejidad: O(n)
void LinkedListHash::flush() {
    // Obtenido parcialmente de: https://www.youtube.com/watch?v=kq4cduYutI8
    // En este video mas que nada me apoye de la logica para eliminar nodos.
    while(!this->isEmpty()) {
        this->removeFirst();
    }
    this->head = nullptr;
    this->tail = nullptr;
}



