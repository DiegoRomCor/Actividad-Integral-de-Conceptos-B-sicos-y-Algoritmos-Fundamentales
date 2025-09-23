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

    int contador = 1;

    while (true) {
        string fechaInicio;
        cout << "Ingresa la fecha inicial (ej: Aug 10): ";

        Entrada fechaI;
        fechaI.leerMesDia(fechaInicio);

        string fechaFin;
        cout << "Ingresa la fecha final (ej: Aug 10): ";

        Entrada fechaF;

        fechaF.leerMesDia(fechaFin);

        string nombre = "salida" + to_string(contador) + "-eq7.txt";

        bitacora.archivoBusqueda(nombre, fechaI, fechaF);
        
        string salir;
        cout<<"¿Deseas continuar? (Y para si, N para no)"<<endl;
        cin>>salir;
        if(salir == "N") {
            break;
        } else {
            contador ++;
        }

    }

    return 0;
}