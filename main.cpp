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
        getline(cin >> ws, fechaInicio);

        int p1 = (int)fechaInicio.find(' ');
        int p2 = (int)fechaInicio.find(' ', p1 + 1);

        string mesStr = fechaInicio.substr(0, p1);
        string diaStr;
        if (p2 == -1) {
            diaStr = fechaInicio.substr(p1 + 1);
        } else {
            diaStr = fechaInicio.substr(p1 + 1, p2 - p1 - 1);
        }

        int diaNum;
        diaNum = stoi(diaStr);

        Entrada fechaI(mesStr, diaNum, 0, 0, 0, "");

        string fechaFin;
        cout << "Ingresa la fecha final (ej: Aug 10): ";
        getline(cin >> ws, fechaFin);

        p1 = (int)fechaFin.find(' ');
        p2 = (int)fechaFin.find(' ', p1 + 1);

        mesStr = fechaFin.substr(0, p1);
        if (p2 == -1) {
            diaStr = fechaFin.substr(p1 + 1);
        } else {
            diaStr = fechaFin.substr(p1 + 1, p2 - p1 - 1);
        }

        diaNum = stoi(diaStr);

        Entrada fechaF(mesStr, diaNum, 0, 0, 0, "");

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