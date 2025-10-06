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

#include "Bitacora.h"
#include "Entrada.h"

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
            int parte1 = linea.find(' '); 
            int parte2 = linea.find(' ', parte1 + 1); 
            int parte3 = linea.find(' ', parte2 + 1); 

            string mes = linea.substr(0, parte1); 
            string dia = linea.substr(parte1 + 1, parte2 - parte1 - 1); 
            string tiempo = linea.substr(parte2 + 1, parte3 - parte2 - 1); 
            string mensaje = linea.substr(parte3 + 1); 
            int tiempo1 = tiempo.find(':'); 

            int tiempo2 = tiempo.find(':', tiempo1 + 1); 
            string hora, minuto, segundo; 
            hora = tiempo.substr(0, tiempo1); 
            minuto = tiempo.substr(tiempo1 + 1, tiempo2 - tiempo1 - 1); 
            segundo = tiempo.substr(tiempo2 + 1);

            // stoi() es una función de la biblioteca estándar que convierte una cadena en un entero.
            // Obtenido de https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp/
            Entrada nuevo(mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo), mensaje); 
            this->vect.push_back(nuevo); 
        }
    }

}

// Complejidad: O(n)
void Bitacora::crearArchivo(string nombre) {
    ofstream archivo(nombre);
    if (archivo.is_open()) {
        for (int i = 0;i < this->vect.size();i++) {
            string mesString = this->vect[i].conversionMes(this->vect[i].getMes());

            // El setw indica que al menos se tienen que encontrar dos caracteres y 
            // setfill indica que si no se encuentra alguno de esos 2 caracteres se agregue un cero
            archivo << mesString << ' '
                << this->vect[i].getDia() << ' '
                << setw(2) << setfill('0') << this->vect[i].getHora() << ':'
                << setw(2) << setfill('0') << this->vect[i].getMinuto() << ':'
                << setw(2) << setfill('0') << this->vect[i].getSegundo()<< ' ' 
                << this->vect[i].getMensaje()
                << '\n';
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
void Bitacora::mezcla(int ini, int fin) {
    if (ini >= fin) {
        return;
    }

    int central = (ini + fin) / 2;
    int i = ini;
    int j = central + 1;

    while (i <= central && j <= fin) {
        if (!comparacionFecha(this->vect[j], this->vect[i])) {
            i++;
        } else {
            Entrada aux = this->vect[j];
            for (int k = j; k > i; --k) {
                this->vect[k] = this->vect[k - 1];
            }
            this->vect[i] = aux;
            i++;
            central++;
            j++;
        }
    }
}


// Complejidad: O(n log n)
void Bitacora::mergeRecursivo(int ini, int fin) {
    if (ini >= fin) return;
    int mid = (ini + fin) / 2;
    mergeRecursivo(ini, mid);
    mergeRecursivo(mid + 1, fin);
    mezcla(ini, fin);
}

// Complejidad: O(n log n)
void Bitacora::mergeSort() {
    mergeRecursivo(0, this->vect.size() - 1);
}

// Complejidad: O(log n)
int Bitacora::buscarBin(Entrada fecha) {
    int inicio = 0;
    int fin = this->vect.size() - 1;
    int medio = 0;
    int resultado = 0;

    while (inicio <= fin) {
        medio = (inicio + fin) / 2;

        if (this->vect[medio].getMes() == fecha.getMes() &&
            this->vect[medio].getDia() == fecha.getDia()) {
            resultado = medio;
            fin = medio - 1;
        } 
        else if (comparacionFecha(this->vect[medio], fecha)) {
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
    for(int i = indexI;(i<this->vect.size() && comparacionFecha(this->vect[i], fechaFinal)) || (this->vect[i].getDia() == fechaFinal.getDia() && this->vect[i].getMes() == fechaFinal.getMes());i++) {
        b.vect.push_back(this->vect[i]);
    }

    b.crearArchivo(nombre);
}