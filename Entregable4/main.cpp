#include "Bitacora.h"
#include "MyHashTable.h"
#include <iostream>
#include <sstream>

int main() {
    Bitacora b;
    b.leerArchivo("bitacora3.txt"); // el archivo que subiste. :contentReference[oaicite:1]{index=1}

    b.mergeSort();

    b.crearArchivo("BitacoraAcomodada.txt");

    Entrada* actual = b.getHead();
    return 0;
}
