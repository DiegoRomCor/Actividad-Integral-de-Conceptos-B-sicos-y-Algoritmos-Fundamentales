//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#include <iostream>
#include <vector>
#include <string>

#include "NodoEntrada.h"

NodoEntrada::NodoEntrada() {
    this->frecuencia = 0;
    this->ip = vector<int>(5, 0);
    this->left = nullptr;
    this->right = nullptr;
}

NodoEntrada::NodoEntrada(int frecuencia, vector<int> ip) {
    this->frecuencia = frecuencia;
    this->ip = ip;
    this->left = nullptr;
    this->right = nullptr;
}

NodoEntrada::NodoEntrada(int frecuencia, vector<int> ip, NodoEntrada* left, NodoEntrada* right) {
    this->frecuencia = frecuencia;
    this->ip = ip;
    this->left = left;
    this->right = right;
}

int NodoEntrada::getFrecuencia() {
    return this->frecuencia;
}

void NodoEntrada::setFrecuencia(int frecuencia) {
    this->frecuencia = frecuencia;
}

vector<int> NodoEntrada::getIp() {
    return this->ip;
}

void NodoEntrada::setIp(vector<int> ip) {
    this->ip = ip;
}

NodoEntrada* NodoEntrada::getLeft() {
    return this->left;
}

void NodoEntrada::setLeft(NodoEntrada* left) {
    this->left = left;
}

NodoEntrada* NodoEntrada::getRight() {
    return this->right;
}

void NodoEntrada::setRight(NodoEntrada* right) {
    this->right = right;
}