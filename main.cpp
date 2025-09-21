#include <bits/stdc++.h>
using namespace std;

class Entrada {
public:
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    int ip;
    string mensaje;
};

int main() {
    // Obtenido con ayuda de: https://www.youtube.com/watch?v=RBZidsPGkfs
    ifstream archivo("bitacora.txt");
    if (archivo.is_open()) {
        vector<string> lineas;
        string linea;
        while (getline(archivo, linea)) {
            lineas.push_back(linea);
        }
        for (const auto &linea : lineas) {
            size_t p1 = linea.find(' ');
            size_t p2 = (p1 == string::npos) ? string::npos : linea.find(' ', p1 + 1);
            size_t p3 = (p2 == string::npos) ? string::npos : linea.find(' ', p2 + 1);

            string mes = linea.substr(0, p1);
            string dia = linea.substr(p1 + 1, p2 - p1 - 1);
            string tiempo = linea.substr(p2 + 1, p3 - p2 - 1);
            string resto = linea.substr(p3 + 1);

            size_t c1 = tiempo.find(':');
            size_t c2 = (c1 == string::npos) ? string::npos : tiempo.find(':', c1 + 1);
            string hora, minuto, segundo;
            hora = tiempo.substr(0, c1);
            minuto = tiempo.substr(c1 + 1, c2 - c1 - 1);
            segundo = tiempo.substr(c2 + 1);

            string ip;
            size_t firstSpace = resto.find(' ');
            string firstToken = (firstSpace == string::npos) ? resto : resto.substr(0, firstSpace);
            if (!firstToken.empty()) {
                bool hasDot = (firstToken.find('.') != string::npos);
                bool hasColon = (firstToken.find(':') != string::npos);
                bool startsWithDigit = isdigit(static_cast<unsigned char>(firstToken[0]));
                if (hasDot && hasColon && startsWithDigit) {
                    ip = firstToken;
                    if (firstSpace == string::npos) resto.clear();
                    else resto = resto.substr(firstSpace + 1);
                }
            }

            cout << "mes=" << mes
                 << " dia=" << dia
                 << " hora=" << hora
                 << " minuto=" << minuto
                 << " segundo=" << segundo;
            if (!ip.empty()) cout << " ip=" << ip;
            cout << " mensaje=" << resto << "\n";
        }
    }
    return 0;
}
