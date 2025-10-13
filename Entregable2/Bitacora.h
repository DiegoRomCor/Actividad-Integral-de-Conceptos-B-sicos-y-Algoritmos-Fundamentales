//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#ifndef BITACORA_H
#define BITACORA_H

#include "Entrada.h"

using namespace std;

class Bitacora {
    private:
        Entrada* head;
        Entrada* tail;

    public:
        Bitacora();
        ~Bitacora();

        // Complejidad: O(n), n siendo la cantidad de Entradas que existen
        void leerArchivo(string nombre);
        // Complejidad: O(n), n siendo la cantidad de Entradas que existen
        void crearArchivo(string nombre);

        Entrada* mezcla(Entrada* a, Entrada* b);    
        Entrada* mergeRecursivo(Entrada* head);     
        void mergeSort(); 

        void busquedaPorIp(string nombre, Entrada ip1, Entrada ip2);
        Entrada* buscaSec(Entrada ip);
};

#endif