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

// Complejidad: O(n)
void ArbolBitacora::destruir(NodoEntrada* actual) {
    if(!actual) {
        return;
    }

    destruir(actual->left);
    destruir(actual->right);
    // Despues de moverte a izquierda y derecha ya puedes eliminar el nodo actual
    delete actual;
}

// Complejidad: O(n)
ArbolBitacora::~ArbolBitacora() {
    destruir(this->root);
    this->root = nullptr;
}

// Complejidad: Mejor caso - O(n log n) // Pero caso - O(n^2) (Es decir, que actue como lista enlazada)
        
void ArbolBitacora::formarArbol(Bitacora b) {
    Entrada* actual = b.getHead();

    while(actual) {
        vector<int> ipActual = actual->getIp();
        int frecuencia = 0;

        while(actual) {
            vector<int> ipSiguiente = actual->getIp();

            bool ipsIguales = true;
            for(int i = 0; i < 4; ++i) {
                if (ipActual[i] != ipSiguiente[i]) {
                    ipsIguales = false;
                    break;
                }
            }

            if(!ipsIguales) {
                break;
            }
            frecuencia++;
            actual = actual->getNext();
        }

        string ipStr = to_string(ipActual[0]) + "." + to_string(ipActual[1]) + "." + to_string(ipActual[2]) + "." + to_string(ipActual[3]);

        if(!this->root) {
            NodoEntrada* nuevoNodo = new NodoEntrada(frecuencia, ipStr);
            this->root = nuevoNodo;
        } else {
            NodoEntrada* nodoActual = this->root;
            while(nodoActual) {
                if(frecuencia > nodoActual->frecuencia) {
                    if (!nodoActual->right) {
                        nodoActual->right = new NodoEntrada(frecuencia, ipStr);
                        break;
                    } else {
                        nodoActual = nodoActual->right;
                    }
                } else if(frecuencia < nodoActual->frecuencia) {
                    if (!nodoActual->left) {
                        nodoActual->left = new NodoEntrada(frecuencia, ipStr);
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

// Complejidad: o(n)
// Obtenido con ayuda de: https://www.youtube.com/watch?v=2hk1Bvuoayo
// https://www.quora.com/How-can-I-print-contents-of-a-tree-in-descending-order 
int ArbolBitacora::imprimirDescendiente(NodoEntrada* actual, int n) {
    if(!actual || n <= 0) {
        return n; 
    }

    // Invertimos el Inorder para imprimir de derecha a izquierda
    n = imprimirDescendiente(actual->right, n);

    for(int i = 0; i < actual->ip.size() && n > 0; ++i) {
        cout<<actual->ip[i]<<" "<<actual->frecuencia<<endl;
        n--; 
    }
    if(n <= 0) {
        return 0;
    }

    n = imprimirDescendiente(actual->left, n);
    return n;
}

// Complejidad: o(n)
void ArbolBitacora::imprimirDescendiente(int n) {
    if(n <= 0) {
        return;
    }
    else if(!root) {
        cout<<"El árbol está vacío"<<endl;
        return;
    }
    // Iniciamos la recursion en la raiz
    imprimirDescendiente(this->root, n);
}
