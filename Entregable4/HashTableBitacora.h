//Diego Romero Corvera A01646496
//Omar Verduzco Velazquez A07019516
//Marco Natsumi Rabiela Mun A01647377

#ifndef HASHTABLEBITACORA_H
#define HASHTABLEBITACORA_H
#include "LinkedListHash.h"

#include "Bitacora.h"

using namespace std;

class HashTableBitacora{
    public://Recuerden que esto sólo lo hacemos para poder revisar las actividades pero debería ser private
        LinkedListHash* tabla;
        int size; //Cantidad de valores que hay almacenados en la tabla
        int sizeA; //Cantidad del arreglo
        // Complejidad: O(n)
        void rehashing(); //Crece el arreglo al doble del tamaño del arreglo actual + 1 // El factor de carga debe ser menor de .75
        // Complejidad: O(1)
        int getPos(string key);

        // Complejidad: O(1)
        HashTableBitacora();  //Tamaño inicial 11
        // Complejidad: O(n)
        ~HashTableBitacora();
        // Complejidad: O(1)
        bool isEmpty(); 
        // Complejidad: O(1)
        void put(string key, string fecha); // No se tiene que validar la key, solo se tiene que insertar
        // Complejidad: O(1)
        vector<string> get(string key);
        // Complejidad: O(1)
        void remove(string key);
            // Complejidad: O(n)
        void crearHashtTable(Bitacora b);
};
#endif