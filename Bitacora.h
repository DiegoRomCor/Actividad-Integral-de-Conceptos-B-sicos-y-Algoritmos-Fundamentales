#ifndef BITACORA_H
#define BITACORA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>

#include "Entrada.h"

using namespace std;

class Bitacora {
    public:
        vector<Entrada> vect;

        Bitacora();

        // Complejidad: O(n)
        void leerArchivo(string nombre);
        // Complejidad: O(n)
        void crearArchivo(string nombre);

        //Complejidad: O(n)
        void mezcla(int ini, int mid, int fin);
        // Complejidad: O(n log n)
        void mergeRecursivo(int ini, int fin);
        // Complejidad: O(n log n)
        void mergeSort();

        // Complejidad: O(log n)
        int buscarBin(Entrada inicio);
        // Complejidad: O(n)
        void archivoBusqueda(string nombre, Entrada fechaInicial, Entrada fechaFinal);

};

#endif