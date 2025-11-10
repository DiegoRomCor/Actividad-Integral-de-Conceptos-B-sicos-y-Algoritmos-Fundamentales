//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#ifndef ARBOLBITACORA_H
#define ARBOLBITACORA_H

#include "Bitacora.h"

using namespace std;

struct NodoEntrada
{   
    int frecuencia;
    vector<string> ip;
    NodoEntrada* left;
    NodoEntrada* right;

    // Complejidad: O(1)
    NodoEntrada() {
        this->frecuencia = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    // Complejidad: O(1)
    NodoEntrada(int frecuencia, string ip) {
        this->frecuencia = frecuencia;
        this->ip.push_back(ip);
        this->left = nullptr;
        this->right = nullptr;
    }
};

class ArbolBitacora {
    private:
        NodoEntrada* root;

        // Complejidad: o(n)
        int imprimirDescendiente(NodoEntrada* actual, int n);

    public:
        // Complejidad: O(1)
        ArbolBitacora();
        // Complejidad: O(n)
        ~ArbolBitacora(); 

        // Complejidad: O(n) - Recorre todos los elementos del arreglo
        void destruir(NodoEntrada* actual);
        
        // Complejidad: Mejor caso - O(n log n) // Pero caso - O(n^2) (Es decir, que actue como lista enlazada)
        void formarArbol(Bitacora b);

        // Complejidad: O(n)
        void imprimirDescendiente(int n);
};

#endif