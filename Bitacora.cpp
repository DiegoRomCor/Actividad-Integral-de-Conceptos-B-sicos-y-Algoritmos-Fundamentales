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
            string mensaje = linea.substr(p3 + 1); int c1 = tiempo.find(':'); 

            int c2 = tiempo.find(':', c1 + 1); string hora, minuto, segundo; 
            hora = tiempo.substr(0, c1); minuto = tiempo.substr(c1 + 1, c2 - c1 - 1); 
            segundo = tiempo.substr(c2 + 1); 

            Entrada nuevo(mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo), mensaje); 
            vect.push_back(nuevo); 
        }
    }

}

void Bitacora::crearArchivo(string nombre) {
    std::ofstream archivo(nombre);
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

void Bitacora::leerBitacora() {
    for(int i = 0;i < vect.size();i++) {
            cout << "mes=" << vect[i].getMes()
                 << " dia=" << vect[i].getDia()
                 << " hora=" << vect[i].getHora()
                 << " minuto=" << vect[i].getMinuto()
                 << " segundo=" << vect[i].getSegundo()
                 << " mensaje=" << vect[i].getMensaje() << "\n";
    }
}

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

//
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

//
void Bitacora::mergeRecursivo(int ini, int fin) {
    if (ini >= fin) return;
    int mid = (ini + fin) / 2;
    mergeRecursivo(ini, mid);
    mergeRecursivo(mid + 1, fin);
    mezcla(ini, mid, fin);
}

//
void Bitacora::mergeSort() {
    return mergeRecursivo(0, vect.size() - 1);
}