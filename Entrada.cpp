#include "Entrada.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

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

Entrada::Entrada(string mes, int dia, int hora, int minuto, int segundo, string mensaje) {
    this->mes = conversionMes(mes);
    this->dia = dia;
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
    this->mensaje = mensaje;
}

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