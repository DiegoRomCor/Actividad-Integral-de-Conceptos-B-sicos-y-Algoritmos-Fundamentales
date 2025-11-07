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

#include "ArbolBitacora.h"
#include "NodoEntrada.h"
#include "Bitacora.h"
#include "Entrada.h"

using namespace std;

// Complejidad: O(1)
ArbolBitacora::ArbolBitacora() {
    this->root = nullptr;
}

// Complejidad: O(n)
ArbolBitacora::~ArbolBitacora() {
    
}