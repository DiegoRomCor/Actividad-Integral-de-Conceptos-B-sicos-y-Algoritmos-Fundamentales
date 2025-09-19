#include <bits/stdc++.h>
using namespace std;

class Entrada {
public:
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    string mensaje;
};

int main() {
    ifstream fin("bitacora.txt");
    if (fin.is_open()) {
        vector<string> lineas;
        string linea;
        while (getline(fin, linea)) {
            lineas.push_back(linea);
        }
        for (const auto &l : lineas) {
            cout << l << '\n';
        }
    }
    return 0;
}
