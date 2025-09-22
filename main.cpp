#include <bits/stdc++.h>
#include <string>
using namespace std;

int convercionMes(string);

string convercionMes(int);

class Entrada {
    public:
        int mes;
        int dia;
        int hora;
        int minuto;
        int segundo;
        string mensaje;

        Entrada(string mes, int dia, int hora, int minuto, int segundo, string mensaje) {
            this->mes = convercionMes(mes);
            this->dia = dia;
            this->hora = hora;
            this->minuto = minuto;
            this->segundo = segundo;
            this->mensaje = mensaje;
        }
};

int convercionMes(string mes) {
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

string convercionMes(int mes) {
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

bool comparacionFecha(Entrada a, Entrada b) {
    if(a.mes != b.mes) {
        return a.mes < b.mes;
    } else if(a.dia != b.dia) {
        return a.dia < b.dia;
    } else if(a.hora != b.hora) {
        return a.hora < b.hora;
    } else if(a.minuto != b.minuto) {
        return a.minuto < b.minuto;
    } else {
        a.segundo < b.segundo;
    }
}

vector<Entrada> Merge() {

}

int main() {
    // Obtenido con ayuda de: https://www.youtube.com/watch?v=RBZidsPGkfs
    ifstream archivo("bitacora.txt");
    if (archivo.is_open()) {
        vector<string> lineas;
        string linea;
        vector<Entrada> lista;
        while (getline(archivo, linea)) {
            lineas.push_back(linea);
            int p1 = linea.find(' ');
            int p2 = linea.find(' ', p1 + 1);
            int p3 = linea.find(' ', p2 + 1);

            string mes = linea.substr(0, p1);
            string dia = linea.substr(p1 + 1, p2 - p1 - 1);
            string tiempo = linea.substr(p2 + 1, p3 - p2 - 1);
            string mensaje = linea.substr(p3 + 1);

            int c1 = tiempo.find(':');
            int c2 = tiempo.find(':', c1 + 1);
            string hora, minuto, segundo;
            hora = tiempo.substr(0, c1);
            minuto = tiempo.substr(c1 + 1, c2 - c1 - 1);
            segundo = tiempo.substr(c2 + 1);

            Entrada nuevo(mes, stoi(dia), stoi(hora), stoi(minuto), stoi(segundo), mensaje);

            lista.push_back(nuevo);

            cout << "mes=" << nuevo.mes
                 << " dia=" << nuevo.dia
                 << " hora=" << nuevo.hora
                 << " minuto=" << nuevo.minuto
                 << " segundo=" << nuevo.segundo
                 << " mensaje=" << nuevo.mensaje << "\n";

        }
    }
    return 0;
}
