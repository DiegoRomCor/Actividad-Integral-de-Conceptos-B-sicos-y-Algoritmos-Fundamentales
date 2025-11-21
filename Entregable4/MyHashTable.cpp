// Diego Romero Corvera A01646496

#include "MyHashTable.h"
#include "MyLinkedList.h"

#include <functional>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stdexcept>

using namespace std;

MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 11;
    this->tabla = new MyLinkedList[this->sizeA];
}

MyHashTable::~MyHashTable() {
    delete[] this->tabla;
    this->tabla = nullptr;
    this->size = 0;
    this->sizeA = 0;
}

int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

bool MyHashTable::isEmpty() {
    return this->size == 0;
}

// CAMBIAR ESTO
void MyHashTable::rehashing() {
    vector<pair<string, vector<string>>> entries;
    entries.reserve(this->size);

    for (int i = 0; i < this->sizeA; ++i) {
        MyNodeLL* actual = this->tabla[i].head;
        while (actual) {
            entries.push_back({actual->key, actual->value});
            actual = actual->next;
        }
    }

    delete[] this->tabla;
    this->sizeA = this->sizeA * 2 + 1;
    this->tabla = new MyLinkedList[this->sizeA];

    for (auto &kv : entries) {
        int posicion = this->getPos(kv.first);
        this->tabla[posicion].insertFirst(kv.first, kv.second);
    }

    this->size = static_cast<int>(entries.size());
}

void MyHashTable::put(string key, string fecha) {
    double carga = (double)(this->size + 1) / (double)this->sizeA;
    if (carga > 0.75) this->rehashing();

    int posicion = this->getPos(key);

    MyNodeLL* nodo = this->tabla[posicion].head;
    while (nodo) {
        if (nodo->key == key) {
            nodo->value.push_back(fecha);
            return;
        }
        nodo = nodo->next;
    }

    vector<string> fechas;
    fechas.push_back(fecha);
    this->tabla[posicion].insertFirst(key, fechas);
    this->size++;
}

vector<string> MyHashTable::get(string key) {
    if (this->isEmpty()) {
        throw invalid_argument("No se puede obtener de una tabla vacía");
    }
    int posicion = this->getPos(key);
    return this->tabla[posicion].getAt(key);
}

void MyHashTable::remove(string key) {
    if (this->isEmpty()) {
        throw invalid_argument("No se puede eliminar de una tabla vacía");
    }
    int posicion = this->getPos(key);
    this->tabla[posicion].removeAt(key);
    this->size--;
}