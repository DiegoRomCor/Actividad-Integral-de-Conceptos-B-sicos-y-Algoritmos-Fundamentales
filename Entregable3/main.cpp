//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

/*
Falta por hacer:
Funcion para agregar los nodos al arbol (Crear el arbol tambien dependiendo de si esta vacio o no root):
    Recorres de Head a Tail la lista enlazada de Bitacora y cuentas cuantas veces se repite la ip, cuando termine el ciclo creas el nodo
    BST Search para ver donde va y lo insertas en el arbol, si es frecuencia igual, lo agregas al vector que toca
Funcion que busque dentro del arbol e imprima las mayores frecuencias (derecha abajo a izquierda arriba):
    
*/

#include "Entrada.h"
#include "Bitacora.h"
#include "ArbolBitacora.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>

#include <climits> 

using namespace std;

int main() {
    Bitacora b;

    b.leerArchivo("bitacora2.txt");

    b.mergeSort();
    b.crearArchivo("bitacoraOrdenadaIP-Eq7-BST.txt");

    ArbolBitacora* ab = new ArbolBitacora();
    ab->formarArbol(b);

    int N;
    cout << "Cuantas IPs quieres ver? ";
    cin >> N;

    cout << "\nTop " << N << " IPs con más accesos:\n";
    ab->imprimirTopN(N);

    return 0;
}