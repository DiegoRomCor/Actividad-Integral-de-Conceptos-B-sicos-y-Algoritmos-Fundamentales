// main.cpp
// Diego Romero Corvera A01646496

#include "Bitacora.h"
#include "MyHashTable.h"
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

// trim derecha (borra espacios y '\r')
static inline void rtrim_inplace(string &s) {
    while(!s.empty() && isspace((unsigned char)s.back())) s.pop_back();
}

int main() {
    Bitacora b;
    
    b.leerArchivo("bitacora.txt");
    b.mergeSort();

    MyHashTable ht;

    

    return 0;
}
