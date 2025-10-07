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
    Bitacora b;

    b.leerArchivo("bitacora.txt");
    /*cout<<"Mes: "<<b.head->getMes()<<endl;
    cout<<"Mes: "<<b.head->getDia()<<endl;
    cout<<"Mes: "<<b.head->getHora()<<endl;
    cout<<"Mes: "<<b.head->getMinuto()<<endl;
    cout<<"Mes: "<<b.head->getSegundo()<<endl;
    vector<int> ip = b.head->getIp();
    cout<<"Ip: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<":"<<ip[4]<<endl;
    cout<<"Mensaje: "<<b.head->getMensaje()<<endl;

    cout<<"Mes: "<<b.tail->getMes()<<endl;
    cout<<"Mes: "<<b.tail->getDia()<<endl;
    cout<<"Mes: "<<b.tail->getHora()<<endl;
    cout<<"Mes: "<<b.tail->getMinuto()<<endl;
    cout<<"Mes: "<<b.tail->getSegundo()<<endl;
    ip = b.tail->getIp();
    cout<<"Ip: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<":"<<ip[4]<<endl;
    cout<<"Mensaje: "<<b.tail->getMensaje()<<endl;*/

}