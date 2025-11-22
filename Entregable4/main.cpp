//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#include "Bitacora.h"
#include "HashTableBitacora.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
    Bitacora b;
    
    b.leerArchivo("bitacora3.txt");
    b.mergeSort();
    b.crearArchivo("BitacoraOrdenada.txt");

    HashTableBitacora ht;
    ht.crearHashtTable(b);

    string ipConsulta;
    int seguir;
    do {
        cout<<"Escribe la ip que quieres consultar (ej: 10.15.175.231):"<<endl;
        cin>>ipConsulta;

        try {
            vector<string> ips = ht.get(ipConsulta);
            for(int i = 0;i < ips.size();i++) {
                cout << ips[i] << endl;
            }
        } catch(const exception &e) {
            cout<<"Ip no encontrada: "<<ipConsulta<<endl;
        }

        cout<<"¿Deseas consultar otra ip? (1 = sí, 0 = no):"<<endl;
        cin>>seguir;
    } while(seguir == 1);

    return 0;
}
