//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>
#include <iomanip>

#include "Bitacora.h"
#include "Entrada.h"

using namespace std;

// Complejidad: O(1)
Bitacora::Bitacora() {
    this->tail = nullptr;
    this->head = nullptr;
}

// Complejidad: O(n)
Bitacora::~Bitacora() {
    Entrada* actual = head;
    while (actual) {
        Entrada* auxiliar = actual->getNext();
        delete actual;
        actual = auxiliar;
    }
}

// Complejidad: O(n)
void Bitacora::leerArchivo(string nombre) {
    // Obtenido con ayuda de: https://www.youtube.com/watch?v=RBZidsPGkfs 
    // En este video explica como usar el ifstream para arbir archivos y leerlos, 
    // me base en eso con otra parte, utilizando el find y el substr
    ifstream archivo(nombre); 
    if (archivo.is_open()) { 
        string linea; 
        while (getline(archivo, linea)) { 
            int parte1 = linea.find(' '); 
            int parte2 = linea.find(' ', parte1 + 1); 
            int parte3 = linea.find(' ', parte2 + 1); 

            string mes = linea.substr(0, parte1); 
            string dia = linea.substr(parte1 + 1, parte2 - parte1 - 1); 
            string tiempo = linea.substr(parte2 + 1, parte3 - parte2 - 1); 
            int tiempo1 = tiempo.find(':'); 
            int tiempo2 = tiempo.find(':', tiempo1 + 1); 
            string hora, minuto, segundo; 
            hora = tiempo.substr(0, tiempo1); 
            minuto = tiempo.substr(tiempo1 + 1, tiempo2 - tiempo1 - 1); 
            segundo = tiempo.substr(tiempo2 + 1);

            string resto = linea.substr(parte3 + 1); 
            int parte4 = resto.find(' '); 
            string strIp = resto.substr(0, parte4);

            // stoi() es una función de la biblioteca estándar que convierte una cadena en un entero.
            // Obtenido de https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp/
            Entrada* nuevo = new Entrada(mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo), linea);
            nuevo->leerIp(strIp);

            if(!this->head) {
                this->head = nuevo;
                this->tail = nuevo;
            } else {
                this->tail->setNext(nuevo);
                this->tail = nuevo;
            }
            
        }
    }

}

// Complejidad: O(n)
void Bitacora::crearArchivo(string nombre) {
    ofstream archivo(nombre);
    if (archivo.is_open()) {
        Entrada* actual = this->head;
        while(actual) {
            archivo << actual->getMensaje() << '\n';
            actual = actual->getNext();
        }

        archivo.close();
    }
}

// Complejidada: O(1)
bool Bitacora::comparacionFecha(Entrada* izquierda, Entrada* derecha) {
    if(izquierda->getMes() != derecha->getMes()) {
        return izquierda->getMes() < derecha->getMes();
    } else if(izquierda->getDia() != derecha->getDia()) {
        return izquierda->getDia() < derecha->getDia();
    } else if(izquierda->getHora() != derecha->getHora()) {
        return izquierda->getHora() < derecha->getHora();
    } else if(izquierda->getMinuto() != derecha->getMinuto()) {
        return izquierda->getMinuto() < derecha->getMinuto();
    } else {
        return izquierda->getSegundo() < derecha->getSegundo();
    }
}

// Obtenido con apoyo de: https://www.baeldung.com/cs/merge-sort-linked-list // Codigo de ejemplo para entender como funciona
// https://interviewkickstart.com/blogs/learn/merge-sort-for-linked-list // En este se muestra un pseudocodigo de como se utiliza, ademas
// muestra el utilizar fast and slow method para combinarlos
// Obtenido con apoyo de: https://www.geeksforgeeks.org/dsa/merge-two-sorted-linked-lists-using-dummy-nodes/
// En esta pagina dan un ejemplo de codigo que utiliza un dummy, o en este caso un auxiliar, lo que facilita el codigo

// Este video fue el que mas ayudo a crear la logica del Merge Sort: https://www.youtube.com/watch?v=8ocB7a_c-Cc

// Complejidad: O(n) - O(size(a) + size(b))
Entrada* Bitacora::mezcla(Entrada* izquierda, Entrada* derecha) {
    // Nodo centinela para simplificar el merge
    Entrada* cabeza = new Entrada();
    Entrada* actual = cabeza;

    while (izquierda && derecha) {
        // Si derecha < izquierda (por fecha), tomar derecha; si no, tomar izquierdizquierda->
        if (this->comparacionFecha(derecha, izquierda)) {
            actual->setNext(derecha);
            derecha = derecha->getNext();
        } else {
            actual->setNext(izquierda);
            izquierda = izquierda->getNext();
        }
        actual = actual->getNext();
    }

    // Adjuntar resto si alguno quedó
    if (izquierda) {
        actual->setNext(izquierda);
    } else if (derecha) {
        actual->setNext(derecha);
    }

    Entrada* auxiliar = cabeza;
    cabeza = cabeza->getNext();
    delete auxiliar;
    return cabeza;
}

Entrada* Bitacora::mergeRecursivo(Entrada* auxiliar) {
    if (!auxiliar || !auxiliar->getNext()) {
        return auxiliar;
    }

    // Slow and fast para encontrar la mitad
    Entrada* lento = auxiliar;
    Entrada* rapido = auxiliar->getNext();
    while (rapido && rapido->getNext()) {
        lento = lento->getNext();
        rapido = rapido->getNext()->getNext();
    }

    Entrada* medio = lento->getNext();
    lento->setNext(nullptr);

    Entrada* izquierda = mergeRecursivo(auxiliar);
    Entrada* derecha   = mergeRecursivo(medio);

    return mezcla(izquierda, derecha);
}

void Bitacora::mergeSort() {
    if (!this->head || !this->head->getNext()) {
        return;
    }

    this->head = mergeRecursivo(this->head);

    // Actualizar tail (último nodo)
    Entrada* actual = this->head;
    while (actual->getNext()) {
        actual = actual->getNext();
    }

    this->tail = actual;
    this->tail->setNext(nullptr);
}

// Complejidad: O(n)
Entrada* Bitacora::buscaSec(Entrada ip) {
    Entrada* actual = head;
    while(actual && actual->getIp()<ip.getIp()) {
        actual = actual->getNext();
    }
    if(!actual) {
        return nullptr;
    } else {
        return actual;
    }
}

// Complejidad: O(n)
void Bitacora::busquedaPorIp(string nombre, Entrada ip1, Entrada ip2) {
    Entrada* inicio = this->buscaSec(ip1);

    ofstream archivo(nombre);
    if (archivo.is_open()) {
        Entrada* actual = inicio;
        while(actual && actual->getIp() <= ip2.getIp()) {
            archivo << actual->getMensaje() << '\n';
            actual = actual->getNext();
        }

        archivo.close();
    }
}

Entrada* Bitacora::getHead() {
    return this->head;
}

void Bitacora::setHead(Entrada* head) {
    this->head = head;
}

Entrada* Bitacora::getTail() {
    return this->tail;
}

void Bitacora::setTail(Entrada* tail) {
    this->tail = tail;
}