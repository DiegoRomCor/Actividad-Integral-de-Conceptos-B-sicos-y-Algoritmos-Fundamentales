//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#ifndef ENTRADA_H
#define ENTRADA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Entrada
{
    private:
        int mes;
        int dia;
        int hora;
        int minuto;
        int segundo;
        vector<int> ip;
        string mensaje;
        Entrada* next;

    public:
        Entrada();
        ~Entrada() {}
        Entrada(string mes, int dia, int hora, int minuto, int segundo, string mensaje);
        Entrada(string mes, int dia, int hora, int minuto, int segundo, vector<int> ip, string mensaje);
        
        // Complejidad: O(1)
        int conversionMes(string mes);

        // Complejidad: O(1)
        void leerMesDia(string linea);
        void leerIp(string linea);

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

        vector<int> getIp();
        void setIp(vector<int> ip);

        string getMensaje();
        void setMensaje(string mensaje);

        Entrada* getNext();
        void setNext(Entrada* next);
};

#endif