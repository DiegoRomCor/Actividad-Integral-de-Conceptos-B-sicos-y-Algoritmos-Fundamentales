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
};

class ArbolBitacora {
    private:
        NodoEntrada* root;

    public:
        ArbolBitacora();
        ~ArbolBitacora(); 
};

#endif