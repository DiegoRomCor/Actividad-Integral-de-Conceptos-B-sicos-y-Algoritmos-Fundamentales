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

        void leerArchivo(string nombre);
        void crearArchivo(string nombre);
        void leerBitacora();

        //Complejidad: O(n)
        void mezcla(int ini, int mid, int fin);
        // Complejidad: O(n log n)
        void mergeRecursivo(int ini, int fin);
        // Complejidad: O(n log n)
        void mergeSort();

        int buscarBin(Entrada inicio);
        void archivoBusqueda(string nombre, Entrada fechaInicial, Entrada fechaFinal);

};