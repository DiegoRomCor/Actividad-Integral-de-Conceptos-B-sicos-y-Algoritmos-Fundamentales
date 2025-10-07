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
    cout<<"Dia: "<<b.head->getDia()<<endl;
    cout<<"Hora: "<<b.head->getHora()<<endl;
    cout<<"Minuto: "<<b.head->getMinuto()<<endl;
    cout<<"Segundo: "<<b.head->getSegundo()<<endl;
    vector<int> ip = b.head->getIp();
    cout<<"Ip: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<":"<<ip[4]<<endl;
    cout<<"Mensaje: "<<b.head->getMensaje()<<endl;

    cout<<"Mes: "<<b.tail->getMes()<<endl;
    cout<<"Dia: "<<b.tail->getDia()<<endl;
    cout<<"Hora: "<<b.tail->getHora()<<endl;
    cout<<"Minuto: "<<b.tail->getMinuto()<<endl;
    cout<<"Segundo: "<<b.tail->getSegundo()<<endl;
    ip = b.tail->getIp();
    cout<<"Ip: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<":"<<ip[4]<<endl;
    cout<<"Mensaje: "<<b.tail->getMensaje()<<endl;

    Entrada* current = b.head->getNext();
    Entrada* current2 = current->getNext();

    cout<<"Mes: "<<current->getMes()<<endl;
    cout<<"Dia: "<<current->getDia()<<endl;
    cout<<"Hora: "<<current->getHora()<<endl;
    cout<<"Minuto: "<<current->getMinuto()<<endl;
    cout<<"Segundo: "<<current->getSegundo()<<endl;
    vector<int> ip = current->getIp();
    cout<<"Ip: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<":"<<ip[4]<<endl;
    cout<<"Mensaje: "<<current->getMensaje()<<endl;

    cout<<"Mes: "<<current2->getMes()<<endl;
    cout<<"Dia: "<<current2->getDia()<<endl;
    cout<<"Hora: "<<current2->getHora()<<endl;
    cout<<"Minuto: "<<current2->getMinuto()<<endl;
    cout<<"Segundo: "<<current2->getSegundo()<<endl;
    ip = current2->getIp();
    cout<<"Ip: "<<ip[0]<<"."<<ip[1]<<"."<<ip[2]<<"."<<ip[3]<<":"<<ip[4]<<endl;
    cout<<"Mensaje: "<<current2->getMensaje()<<endl;*/

}