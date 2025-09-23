#include "Bitacora.h"
#include "Entrada.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

Bitacora::Bitacora() {

}

// Complejidad: O(n)
void Bitacora::leerArchivo(string nombre) {
    // Obtenido con ayuda de: https://www.youtube.com/watch?v=RBZidsPGkfs 
    ifstream archivo(nombre); 
    if (archivo.is_open()) { 
        string linea; 
        while (getline(archivo, linea)) { 
            int p1 = linea.find(' '); 
            int p2 = linea.find(' ', p1 + 1); 
            int p3 = linea.find(' ', p2 + 1); 

            string mes = linea.substr(0, p1); 
            string dia = linea.substr(p1 + 1, p2 - p1 - 1); 
            string tiempo = linea.substr(p2 + 1, p3 - p2 - 1); 
            string mensaje = linea.substr(p3 + 1); 
            int c1 = tiempo.find(':'); 

            int c2 = tiempo.find(':', c1 + 1); string hora, minuto, segundo; 
            hora = tiempo.substr(0, c1); minuto = tiempo.substr(c1 + 1, c2 - c1 - 1); 
            segundo = tiempo.substr(c2 + 1);

            Entrada nuevo(mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo), mensaje); 
            vect.push_back(nuevo); 
        }
    }

}

// Complejidad: O(n)
void Bitacora::crearArchivo(string nombre) {
    ofstream archivo(nombre);
    if (archivo.is_open()) {
        for (int i = 0;i < vect.size();i++) {
            string mesString = vect[i].conversionMes(vect[i].getMes());

            archivo << mesString << ' '
                << vect[i].getDia() << ' '
                << setw(2) << setfill('0') << vect[i].getHora() << ':'
                << setw(2) << setfill('0') << vect[i].getMinuto() << ':'
                << setw(2) << setfill('0') << vect[i].getSegundo()
                << ' ' << vect[i].getMensaje();

            archivo << '\n';
        }

        archivo.close();
    }
}

// Complejidad: O(1)
bool comparacionFecha(Entrada a, Entrada b) {
    if(a.getMes() != b.getMes()) {
        return a.getMes() < b.getMes();
    } else if(a.getDia() != b.getDia()) {
        return a.getDia() < b.getDia();
    } else if(a.getHora() != b.getHora()) {
        return a.getHora() < b.getHora();
    } else if(a.getMinuto() != b.getMinuto()) {
        return a.getMinuto() < b.getMinuto();
    } else {
        return a.getSegundo() < b.getSegundo();
    }
}

// Complejidad: O(n)
void Bitacora::mezcla(int ini, int mid, int fin) {
    int i = ini;
    int j = mid + 1;
    vector<Entrada> tmp;
    tmp.reserve(fin - ini + 1);
    int comparaciones = 0;

    while (i <= mid && j <= fin) {
        comparaciones++;
        if (comparacionFecha(vect[i], vect[j])) {
            tmp.push_back(vect[i++]);
        } else {
            tmp.push_back(vect[j++]);
        }
    }

    while (i <= mid) tmp.push_back(vect[i++]);
    while (j <= fin) tmp.push_back(vect[j++]);


    for (int k = 0; k < (int)tmp.size(); ++k) {
        vect[ini + k] = std::move(tmp[k]);
    }
}

// Complejidad: O(n log n)
void Bitacora::mergeRecursivo(int ini, int fin) {
    if (ini >= fin) return;
    int mid = (ini + fin) / 2;
    mergeRecursivo(ini, mid);
    mergeRecursivo(mid + 1, fin);
    mezcla(ini, mid, fin);
}

// Complejidad: O(n log n)
void Bitacora::mergeSort() {
    mergeRecursivo(0, vect.size() - 1);
}

// Complejidad: O(log n)
int Bitacora::buscarBin(Entrada fecha) {
    int inicio = 0;
    int fin = vect.size() - 1;
    int medio = 0;
    int resultado = 0;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;

        if (vect[medio].getMes() == fecha.getMes() &&
            vect[medio].getDia() == fecha.getDia()) {
            resultado = medio;
            fin = medio - 1;
        } 
        else if (comparacionFecha(vect[medio], fecha)) {
            inicio = medio + 1;
        } 
        else {
            fin = medio - 1;
        }
    }

    return resultado;
}

// Complejidad: O(n)
void Bitacora::archivoBusqueda(string nombre, Entrada fechaInicial, Entrada fechaFinal) {
    int indexI = buscarBin(fechaInicial);

    Bitacora b;
    for(int i = indexI;i<vect.size() && comparacionFecha(vect[i], fechaFinal) || (vect[i].getDia() == fechaFinal.getDia() && vect[i].getMes() == fechaFinal.getMes());i++) {
        b.vect.push_back(vect[i]);
    }

    b.crearArchivo(nombre);
}