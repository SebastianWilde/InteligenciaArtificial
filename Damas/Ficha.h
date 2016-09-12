#ifndef FICHA_H_INCLUDED
#define FICHA_H_INCLUDED
#include <vector>
#include <iostream>
using namespace std;
struct Ficha
{
    char ficha;
 //   bool tipo; //Si es 0 es ficha normal, si es 1 tiene corona
    bool color; //Si es 0 es rojo, se mueve hacia abajo, 1 es negro se mueve hacia arriba
    int posx, posy;
    int tam; //Tamaño del tablero
    Ficha(bool col,int Size,int x, int y)
    {
        color=col;
//        tipo=0;
        if (color==0) ficha='R';
        else ficha='N';
        tam=Size;
        posx=x;
        posy=y;
        return;
    }
    void Print()
    {
        cout<<endl<<"Ficha: "<<posx<<" , "<<posy<<endl;
    }
};


#endif // FICHA_H_INCLUDED
