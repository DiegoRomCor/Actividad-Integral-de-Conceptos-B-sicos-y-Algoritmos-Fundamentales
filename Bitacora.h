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

        //
        void mezcla(int ini, int mid, int fin);

        //
        void mergeRecursivo(int ini, int fin);

        //
        void mergeSort();

};