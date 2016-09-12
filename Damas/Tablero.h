#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include <iostream>
#include "Ficha.h"
using namespace std;
class Tablero
{
    public:
    vector <Ficha * > Jugador1;
    vector <Ficha * > Jugador2;
    bool turno; // 0 turno del jugador, 1 turno de la maquina
    vector

};

#endif // TABLERO_H_INCLUDED
