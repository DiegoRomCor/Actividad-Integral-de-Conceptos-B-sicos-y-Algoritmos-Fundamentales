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
    this->size = 0;
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

            if(this->size == 0) {
                this->head = nuevo;
                this->tail = nuevo;
            } else {
                this->tail->setNext(nuevo);
                this->tail = nuevo;
            }

            this->size++; 
            
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

// Obtenido con apoyo de: https://www.baeldung.com/cs/merge-sort-linked-list // Codigo de ejemplo para entender como funciona
// https://interviewkickstart.com/blogs/learn/merge-sort-for-linked-list // En este se muestra un pseudocodigo de como se utiliza, ademas
// muestra el utilizar fast and slow method para combinarlos
// Obtenido con apoyo de: https://www.geeksforgeeks.org/dsa/merge-two-sorted-linked-lists-using-dummy-nodes/
// En esta pagina dan un ejemplo de codigo que utiliza un dummy, o en este caso un auxiliar, lo que facilita el codigo

// Complejidad: O(n)
Entrada* Bitacora::mezcla(Entrada* a, Entrada* b) {
    Entrada auxiliar;
    Entrada* cola = &auxiliar;

    while(a && b) {
        if (b->getIp() < a->getIp()) {
            cola->setNext(b);
            b = b->getNext();
        } else {
            cola->setNext(a);
            a = a->getNext();
        }
        cola = cola->getNext();
    }

    if(a) {
        cola->setNext(a);
    }
    else{
        cola->setNext(b);
    }

    return auxiliar.getNext();
}

// Complejidad: O(log n)
Entrada* Bitacora::mergeRecursivo(Entrada* auxiliar) {
    if(!auxiliar || !auxiliar->getNext()) {
        return auxiliar;
    } 

    // Encontrar la mitad de la lista actual usando el metodo Slow and Fast
    Entrada* lento = auxiliar;
    Entrada* rapido = auxiliar->getNext();
    while(rapido && rapido->getNext()) {
        lento = lento->getNext();
        rapido = rapido->getNext()->getNext();
    }

    Entrada* medio = lento->getNext();
    // Hacemos que apunte a null, para poder dividir la lista, 
    // al hacer que pare en el while anterior, des esta forma dividimos de mitad en mitad
    lento->setNext(nullptr);

    Entrada* izquierda = mergeRecursivo(auxiliar);
    Entrada* derecha   = mergeRecursivo(medio);

    return mezcla(izquierda, derecha);
}

// Complejidad: O(n log n)
void Bitacora::mergeSort() {
    if(this->size == 0 || this->size == 1) {
        return;
    } 

    this->head = mergeRecursivo(this->head);

    // Esto es necesario para dejar el tail hasta el final de la lista, 
    // ya que movimos toda la lista
    Entrada* actual = this->head;
    while(actual->getNext()) {
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
    Entrada* fin = this->buscaSec(ip2);

    ofstream archivo(nombre);
    if (archivo.is_open()) {
        Entrada* actual = inicio;
        while(actual != fin) {
            archivo << actual->getMensaje() << '\n';
            actual = actual->getNext();
        }

        archivo.close();
    }
}
