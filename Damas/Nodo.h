#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <iostream>
#include "Tablero.h"
#include <vector>
using namespace std;
struct Nodo
{
    Tablero Tab;
    Nodo* To_Padre;
    vector<Nodo*> hijos;
    bool Identificador; //Saber si es donde se hace min o max
    int MinMax; //Valor MinMax Optenido
};
#endif // NODO_H_INCLUDED
