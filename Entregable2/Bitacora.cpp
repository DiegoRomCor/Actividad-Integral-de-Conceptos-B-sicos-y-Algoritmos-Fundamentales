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

Bitacora::Bitacora() {
    this->tail = nullptr;
    this->head = nullptr;
    this->size = 0;
}

Bitacora::~Bitacora() {

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