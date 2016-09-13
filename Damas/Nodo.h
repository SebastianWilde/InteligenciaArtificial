#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED
#include <iostream>
#include "Tablero.h"
#include <vector>
using namespace std;
struct Nodo
{
    Nodo* To_Padre;
    vector<Nodo*> hijos;
    typedef Tablero Tablero;
    Tablero *Tab;
    bool Whom_move; //Saber si se mueven las fichas de la maquina (0) o del jugador (1)
    int heruristica; //Resta entre las fichas de la maquina y del jugador
    int Who_move; //Saber que ficha se mueve
    bool where_move;//Saber hacia donde se mueve, izquierda o derecha
//    int MinMax;//Valor de minmax
    Nodo(){}
    Nodo(Tablero T)
    {
        Tab=new Tablero(T.tam);
        *Tab=T;
        heruristica=Tab->Jugador1.size()-Tab->Jugador1.size();
    }
    Nodo(Tablero T, bool whom,int who, bool where)
    {
        Tab=new Tablero(T.tam);
        *Tab=T;
        heruristica=Tab->Jugador1.size()-Tab->Jugador1.size();
        Whom_move=whom;
        Who_move=who;
        where_move=where;
    }
    int Mayor()
    {
        int mayor=0;
        for(int i=1;i<(int)hijos.size();i++)
            if (hijos[i]->heruristica>hijos[mayor]->heruristica) mayor=i;
        return mayor;
    }
    int Menor()
    {
        int menor=0;
        for(int i=1;i<(int)hijos.size();i++)
            if (hijos[i]->heruristica>hijos[menor]->heruristica) menor=i;
        return menor;
    }
};
#endif // NODO_H_INCLUDED
