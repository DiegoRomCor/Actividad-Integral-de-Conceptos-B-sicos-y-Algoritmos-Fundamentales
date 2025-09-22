#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>

#include "Entrada.h"
#include "Bitacora.h"

using namespace std;



int main() {
    Bitacora bitacora;

    bitacora.leerArchivo("bitacora.txt");
    
    bitacora.mergeSort();

    bitacora.crearArchivo("bitacoraOrdenada1.3-eq7.txt");

    return 0;
}