// Diego Romero Corvera A01646496

#include "Entrada.h"
#include "Bitacora.h"
#include "MyHashTable.h"
#include "MyLinkedList.h"

#include <functional>
#include <vector>
#include <utility>
#include <cstdlib>
#include <stdexcept>

using namespace std;

// Complejidad: O(1)
MyHashTable::MyHashTable(){
    this->size = 0;
    this->sizeA = 601;
    this->tabla = new MyLinkedList[this->sizeA];
}

// Complejidad: O(1)
MyHashTable::~MyHashTable() {
    delete[] this->tabla;
    this->tabla = nullptr;
    this->size = 0;
    this->sizeA = 0;
}

// Complejidad: O(1)
int MyHashTable::getPos(string key){
    size_t hashC=hash<string>{}(key);
    int hashCode=static_cast<int>(hashC);
    return abs(hashCode)%this->sizeA;
}

// Complejidad: O(1)
bool MyHashTable::isEmpty() {
    return this->size == 0;
}

// Obtenido con ayuda de: https://www.youtube.com/watch?v=uaGWFN6djLw&embeds_referring_euri=https%3A%2F%2Fchatgpt.com%2F&source_ve_path=OTY3MTQ 
// https://www.youtube.com/watch?v=2_3fR-k-LzI
// Complejidad: O(n)
void MyHashTable::rehashing() {
    // Primero se extraen todos las parejas de valores que se tienen
    vector<string> claves;
    vector<vector<string>> valores;

    for(int i = 0; i < this->sizeA; ++i) {
        MyNodeLL* actual = this->tabla[i].head;
        while(actual) {
            claves.push_back(actual->key);
            valores.push_back(actual->value);
            actual = actual->next;
        }
    }
    delete[] this->tabla;

    // Nuevo tama;o de la tabla
    this->sizeA = this->sizeA * 2 + 1;
    this->tabla = new MyLinkedList[this->sizeA];

    // Se insertan los valores de antes en la nueva tabla creada
    this->size = 0;
    for(int i = 0; i < claves.size(); ++i) {
        int posicion = this->getPos(claves[i]);
        this->tabla[posicion].insertFirst(claves[i], valores[i]);
        this->size++;
    }
}

// Complejidad: O(1)
void MyHashTable::put(string key, string fecha) {
    double carga =(double)(this->size + 1) /(double)this->sizeA;
    if(carga > 0.75) {
        this->rehashing();
    }

    int posicion = this->getPos(key);

    MyNodeLL* nodo = this->tabla[posicion].head;
    while(nodo) {
        if(nodo->key == key) {
            nodo->value.push_back(fecha);
            return;
        }
        nodo = nodo->next;
    }

    // Si no se encuentra en los nodos significa que no esta, por lo que se agrega uno nuevo obteniendo la posicion
    vector<string> fechas;
    fechas.push_back(fecha);
    this->tabla[posicion].insertFirst(key, fechas);
    this->size++;
}

// Complejidad: O(1) -- Peor caso O(n)
vector<string> MyHashTable::get(string key) {
    if(this->isEmpty()) {
        throw invalid_argument("No se puede obtener de una tabla vacía");
    }
    int posicion = this->getPos(key);
    return this->tabla[posicion].getAt(key);
}

// Complejidad: O(1) -- Peor caso O(n)
void MyHashTable::remove(string key) {
    if(this->isEmpty()) {
        throw invalid_argument("No se puede eliminar de una tabla vacía");
    }
    int posicion = this->getPos(key);
    this->tabla[posicion].removeAt(key);
    this->size--;
}

string convertirFecha(int mes) {
    if(mes == 1) {
        return "Jan";
    } else if(mes == 2) {
        return "Feb";
    } else if(mes == 3) {
        return "Mar";
    } else if(mes == 4) {
        return "Apr";
    } else if(mes == 5) {
        return "May";
    } else if(mes == 6) {
        return "Jun";
    } else if(mes == 7) {
        return "Jul";
    } else if(mes == 8) {
        return "Aug";
    } else if(mes == 9) {
        return "Sep";
    } else if(mes == 10) {
        return "Oct";
    } else if(mes == 11) {
        return "Nov";
    } else if(mes == 12) {
        return "Dec";
    }

    return " ";
}

// Complejidad: O(n)
void MyHashTable::crearHashtTable(Bitacora b) {
    Entrada* actual = b.getHead();
    while(actual) {
        // Convertimos la IP en un string
        vector<int> ip = actual->getIp();
        string clave = to_string(ip[0]) + "." + to_string(ip[1]) + "." + to_string(ip[2]) + "." + to_string(ip[3]);

        // Convertimos la Fecha y Hora en String
        string hora = "";
        string minuto = "";
        string segundo = "";
        if(actual->getHora() < 10) {
            hora = "0";
        }
        if(actual->getMinuto() < 10) {
            minuto = "0";
        }
        if(actual->getSegundo() < 10) {
            segundo = "0";
        }

        hora += to_string(actual->getHora());
        minuto += to_string(actual->getMinuto());
        segundo += to_string(actual->getSegundo());

        string fecha = convertirFecha(actual->getMes()) + " " + to_string(actual->getDia()) + " " + hora + ":" + minuto + ":" + segundo;

        // Insertamos en la HashTable
        this->put(clave, fecha);

        actual = actual->getNext();
    }

}