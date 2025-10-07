//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#include "Entrada.h"
#include "Bitacora.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>

using namespace std;

int main() {
    Entrada Primero;

    string s = "192.168.100.2:502";

    Primero.leerIp(s);

    vector<int> v = Primero.getIp();

    cout<<v[0]<<"."<<v[1]<<"."<<v[2]<<"."<<v[3]<<":"<<v[4];
}