//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#ifndef ENTRADA_H
#define ENTRADA_H

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
        Entrada();
        Entrada(string mes, int dia, int hora, int minuto, int segundo);
        Entrada(string mes, int dia, int hora, int minuto, int segundo, string mensaje);
        // Complejidad: O(1)
        int conversionMes(string mes);
        string conversionMes(int mes);

        void leerMesDia(string linea);

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