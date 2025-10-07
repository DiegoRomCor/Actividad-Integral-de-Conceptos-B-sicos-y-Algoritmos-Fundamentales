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

using namespace std;

Entrada::Entrada() {
    this->mes = 0;
    this->dia = 0;
    this->hora = 0;
    this->minuto = 0;
    this->segundo = 0;
    this->ip = vector<int>(5, 0);
    this->mensaje = "";
    this->next = nullptr;
}

Entrada::Entrada(string mes, int dia, int hora, int minuto, int segundo, vector<int> ip) {
    this->mes = conversionMes(mes);
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->ip = ip;
    this->next = nullptr;
}

Entrada::Entrada(string mes, int dia, int hora, int minuto, int segundo, vector<int> ip, string mensaje) {
    this->mes = conversionMes(mes);
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->ip = ip;
    this->mensaje = mensaje;
    this->next = nullptr;
}

int Entrada::conversionMes(string mes) {
    if(mes == "Jan") {
        return 1;
    } else if(mes == "Feb") {
        return 2;
    } else if(mes == "Mar") {
        return 3;
    } else if(mes == "Apr") {
        return 4;
    } else if(mes == "May") {
        return 5;
    } else if(mes == "Jun") {
        return 6;
    } else if(mes == "Jul") {
        return 7;
    } else if(mes == "Aug") {
        return 8;
    } else if(mes == "Sep") {
        return 9;
    } else if(mes == "Oct") {
        return 10;
    } else if(mes == "Nov") {
        return 11;
    } else if(mes == "Dec") {
        return 12;
    }

    return 0;
}

void Entrada::leerMesDia(string linea) {
    int punto1 = linea.find(' ');

    string mesString = linea.substr(0, punto1);
    string diaString;

    diaString = linea.substr(punto1 + 1);

    int diaNumero;
    // stoi() es una función de la biblioteca estándar que convierte una cadena en un entero.
    // Obtenido de https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp/
    diaNumero = stoi(diaString);

    this->setMes(this->conversionMes(mesString));
    this->setDia(diaNumero);
}

void Entrada::leerIp(string linea) {
    vector<int> resultado;

    int punto1 = (int)linea.find('.', 0);
    int punto2 = (int)linea.find('.', punto1 + 1);
    int punto3 = (int)linea.find('.', punto2 + 1);
    int dosPuntos = (int)linea.find(':', punto3 + 1);

    string seccion1 = linea.substr(0, punto1 - 0);
    string seccion2 = linea.substr(punto1 + 1, punto2 - punto1 - 1);
    string seccion3 = linea.substr(punto2 + 1, punto3 - punto2 - 1);
    string seccion4 = linea.substr(punto3 + 1, dosPuntos - punto3 - 1);
    string seccionPuerto = linea.substr(dosPuntos + 1);

    int o1 = stoi(seccion1);
    int o2 = stoi(seccion2);
    int o3 = stoi(seccion3);
    int o4 = stoi(seccion4);
    int numPuerto = stoi(seccionPuerto);

    resultado.push_back(o1);
    resultado.push_back(o2);
    resultado.push_back(o3);
    resultado.push_back(o4);
    resultado.push_back(numPuerto);

    this->ip = resultado;
}


// Getters y Setters para las variables privadas
int Entrada::getMes() {
    return this->mes;
}

void Entrada::setMes(int mes) {
    this->mes = mes;
}

int Entrada::getDia() {
    return this->dia;
}

void Entrada::setDia(int dia){
    this->dia = dia;
}

int Entrada::getHora() {
    return this->hora;
}

void Entrada::setHora(int hora) {
    this->hora = hora;
}

int Entrada::getMinuto() {
    return this->minuto;
}

void Entrada::setMinuto(int minuto) {
    this->minuto = minuto;
}

int Entrada::getSegundo() {
    return this->segundo;
}

void Entrada::setSegundo(int segundo) {
    this->segundo = segundo;
}

vector<int> Entrada::getIp() {
    return this->ip;
}

void Entrada::setIp(vector<int> ip) {
    this->ip = ip;
}

string Entrada::getMensaje() {
    return this->mensaje;
}

void Entrada::setMensaje(string mensaje) {
    this->mensaje = mensaje;
}

Entrada* Entrada::getNext() {
    return this->next;
}

void Entrada::setNext(Entrada* next) {
    this->next = next;
}
