//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#include "Entrada.h"
#include "Bitacora.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main() {
    Bitacora b;

    b.leerArchivo("bitacora.txt");

    b.mergeSort();
    b.crearArchivo("bitacoraOrdenadaIP-Eq7.txt");

    int contador = 1;

    string salir;

    do {
        string ipInicio;
        Entrada ip1;

        cout << "Ingresa la ip inicial (ej: 961.43.478.18): ";
        cin>>ipInicio;
        ipInicio+=":0";
        ip1.leerIp(ipInicio);

        string ipFin;
        Entrada ip2;

        cout << "Ingresa la ip final (ej: 961.43.478.18): ";
        cin>>ipFin;
        ipFin+=":9999";
        ip2.leerIp(ipFin);

        string nombre = "salida" + to_string(contador) + "-Eq7.txt";
        b.busquedaPorIp(nombre, ip1, ip2);
        
        
        cout<<"Deseas continuar? (Y para si, N para no)"<<endl;
        cin>>salir;
        contador++;

    } while(salir == "Y" || salir == "y");

    return 0;
}