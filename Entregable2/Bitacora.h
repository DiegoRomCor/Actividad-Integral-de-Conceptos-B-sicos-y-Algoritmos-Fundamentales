//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#ifndef BITACORA_H
#define BITACORA_H

#include "Entrada.h"

using namespace std;

class Bitacora {
    public:
        Entrada* head;
        Entrada* tail;
        int size;

        Bitacora();
        ~Bitacora();

        // Complejidad: O(n), n siendo la cantidad de Entradas que existen
        void leerArchivo(string nombre);
        // Complejidad: O(n), n siendo la cantidad de Entradas que existen
        void crearArchivo(string nombre);

        //Complejidad: O(n)
        void mezcla(int ini, int fin);
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