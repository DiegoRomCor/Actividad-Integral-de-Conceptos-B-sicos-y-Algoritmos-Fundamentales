//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

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
        Entrada fechaI;

        cout << "Ingresa la fecha inicial (ej: Aug 10): ";
        fechaI.leerMesDia(fechaInicio);

        string fechaFin;
        Entrada fechaF;

        cout << "Ingresa la fecha final (ej: Aug 10): ";
        fechaF.leerMesDia(fechaFin);

        string nombre = "salida" + to_string(contador) + "-eq7.txt";
        bitacora.archivoBusqueda(nombre, fechaI, fechaF);
        
        string salir;
        cout<<"Deseas continuar? (Y para si, N para no)"<<endl;
        cin>>salir;
        if(salir == "N") {
            break;
        } else {
            contador++;
        }

    }

    return 0;
}