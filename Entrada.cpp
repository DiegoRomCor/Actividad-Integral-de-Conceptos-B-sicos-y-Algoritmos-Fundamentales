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

}

Entrada::Entrada(string mes, int dia, int hora, int minuto, int segundo) {
    this->mes = conversionMes(mes);
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

Entrada::Entrada(string mes, int dia, int hora, int minuto, int segundo, string mensaje) {
    this->mes = conversionMes(mes);
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->mensaje = mensaje;
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

string Entrada::conversionMes(int mes) {
    if(mes == 1) {
        return "Jan";
    } else if(mes == 2) {
        return "Feb";
    } else if(mes == 3) {
        return "Mar";
    } else if(mes == 4) {
        return "Apr";
    } else if(mes == 5) {
        return "May";
    } else if(mes == 6) {
        return "Jun";
    } else if(mes == 7) {
        return "Jul";
    } else if(mes == 8) {
        return "Aug";
    } else if(mes == 9) {
        return "Sep";
    } else if(mes == 10) {
        return "Oct";
    } else if(mes == 11) {
        return "Nov";
    } else if(mes == 12) {
        return "Dec";
    }

    return " ";
}

void Entrada::leerMesDia(string linea) {
    //  Es una combinación en C++ que primero consume los espacios en blanco iniciales de la entrada estándar 
    // (cin >> ws) y luego usa la función std::getline para leer toda una línea de texto, incluyendo espacios, 
    // y almacenarla en la variable linea hasta que encuentra un salto de línea.
    getline(cin >> ws, linea);
    int parte1 = linea.find(' ');

    string mesString = linea.substr(0, parte1);
    string diaString;

    diaString = linea.substr(parte1 + 1);

    int diaNumero;
    // stoi() es una función de la biblioteca estándar que convierte una cadena en un entero.
    // Obtenido de https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp/
    diaNumero = stoi(diaString);

    this->setMes(this->conversionMes(mesString));
    this->setDia(diaNumero);
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

string Entrada::getMensaje() {
    return this->mensaje;
}

void Entrada::setMensaje(string mensaje) {
    this->mensaje = mensaje;
}