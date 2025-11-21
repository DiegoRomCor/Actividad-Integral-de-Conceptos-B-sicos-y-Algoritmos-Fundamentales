// Diego Romero Corvera
// A01646496

#ifndef MYHASHTABLE_H
#define MYHASHTABLE_H
#include "MyLinkedList.h" // <----------------- Cambiar esto en caso de que se utilice otra lista enlazada
//En caso de utilizar tu lista enlazada recuerda también enviar el archivo para poder compilar y ejecutar el programa

using namespace std;

class MyHashTable{
    public://Recuerden que esto sólo lo hacemos para poder revisar las actividades pero debería ser private
       MyLinkedList* tabla;
       int size; //Cantidad de valores que hay almacenados en la tabla
       int sizeA; //Cantidad del arreglo
       // Complejidad: O(n)
       void rehashing(); //Crece el arreglo al doble del tamaño del arreglo actual + 1 // El factor de carga debe ser menor de .75
       // Complejidad: O(1)
       int getPos(string key);

       // Complejidad: O(1)
       MyHashTable();  //Tamaño inicial 11
       // Complejidad: O(n)
       ~MyHashTable();
       // Complejidad: O(1)
       bool isEmpty(); 
       // Complejidad: O(1)
       void put(string key, string fecha); // No se tiene que validar la key, solo se tiene que insertar
       // Complejidad: O(1)
       vector<string> get(string key);
       // Complejidad: O(1)
       void remove(string key);
};
#endif