#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

class Entrada {
    private:
        int mes;
        int dia;
        int hora;
        int minuto;
        int segundo;
        string mensaje;

    public:
        Entrada(string mes, int dia, int hora, int minuto, int segundo);
        Entrada(string mes, int dia, int hora, int minuto, int segundo, string mensaje);
        int conversionMes(string mes);
        string conversionMes(int mes);

        int getMes();
        void setMes(int mes);

        int getDia();
        void setDia(int dia);

        int getHora();
        void setHora(int hora);

        int getMinuto();
        void setMinuto(int minuto);

        int getSegundo();
        void setSegundo(int segundo);

        string getMensaje();
        void setMensaje(string mensaje);

};

#endif