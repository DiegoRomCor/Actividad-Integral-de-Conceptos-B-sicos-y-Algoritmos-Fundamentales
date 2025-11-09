//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#include <iostream>
#include <vector>

#include "ArbolBitacora.h"
#include "Bitacora.h"
#include "Entrada.h"

using namespace std;

// Complejidad: O(1)
ArbolBitacora::ArbolBitacora() {
    this->root = nullptr;
}

void ArbolBitacora::destruir(NodoEntrada* actual) {
    if (!actual) {
        return;
    }
    destruir(actual->left);
    destruir(actual->right);
    delete actual;
}

ArbolBitacora::~ArbolBitacora() {
    destruir(this->root);
    this->root = nullptr;
}

void ArbolBitacora::formarArbol(Bitacora b) {
    Entrada* actual = b.getHead();

    while (actual) {
        vector<int> ipActual = actual->getIp();
        int frecuencia = 0;

        while (actual) {
            vector<int> ipSiguiente = actual->getIp();

            bool ipsIguales = true;
            for (int i = 0; i < 4; ++i) {
                if (ipActual[i] != ipSiguiente[i]) {
                    ipsIguales = false;
                    break;
                }
            }

            if (!ipsIguales) {
                break;
            }
            frecuencia++;
            actual = actual->getNext();
        }

        string ipStr = to_string(ipActual[0]) + "." + to_string(ipActual[1]) + "." + to_string(ipActual[2]) + "." + to_string(ipActual[3]);

        if (!this->root) {
            NodoEntrada* nuevoNodo = new NodoEntrada();
            nuevoNodo->frecuencia = frecuencia;
            nuevoNodo->ip.push_back(ipStr);
            nuevoNodo->left = nullptr;
            nuevoNodo->right = nullptr;
            this->root = nuevoNodo;
        } else {
            NodoEntrada* nodoActual = this->root;
            while (nodoActual) {
                if (frecuencia > nodoActual->frecuencia) {
                    if (!nodoActual->right) {
                        nodoActual->right = new NodoEntrada();
                        NodoEntrada* nuevoNodo = nodoActual->right;
                        nuevoNodo->frecuencia = frecuencia;
                        nuevoNodo->ip.push_back(ipStr);
                        nuevoNodo->left = nullptr;
                        nuevoNodo->right = nullptr;
                        break;
                    } else {
                        nodoActual = nodoActual->right;
                    }
                } else if (frecuencia < nodoActual->frecuencia) {
                    if (!nodoActual->left) {
                        nodoActual->left = new NodoEntrada();
                        NodoEntrada* nuevoNodo = nodoActual->left;
                        nuevoNodo->frecuencia = frecuencia;
                        nuevoNodo->ip.push_back(ipStr);
                        nuevoNodo->left = nullptr;
                        nuevoNodo->right = nullptr;
                        break;
                    } else {
                        nodoActual = nodoActual->left;
                    }
                } else {
                    nodoActual->ip.push_back(ipStr);
                    break;
                }
            }
        }
    }
}


void ArbolBitacora::imprimirTopN(int n) {
    if (!root) {
        cout << "El árbol está vacío.\n";
        return;
    }

    int contador = 0;
    imprimirTopNRec(root, n, contador);
}

void ArbolBitacora::imprimirTopNRec(NodoEntrada* actual, int n, int& contador) {
    if (!actual || contador >= n) {
        return;
    }

    imprimirTopNRec(actual->right, n, contador);

    for (int i = 0;i < actual->ip.size();i++) {
        if (contador < n) {
            cout << actual->ip[i] << " " << actual->frecuencia << endl;
            contador++;
        } else {
            break;
        }
    }

    imprimirTopNRec(actual->left, n, contador);
}
