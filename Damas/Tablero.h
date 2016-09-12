#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include <iostream>
#include "Ficha.h"
#include <string>
using namespace std;
class Tablero
{
    public:
    vector <Ficha * > Jugador1;
    vector <Ficha * > Jugador2;
    bool turno; // 0 turno del jugador, 1 turno de la maquina
    char **Tabla;
    int tam;
    bool Fin; //0 es que aun no ha acabo el juego
    void PrintTablero();
    void ActulizarTablero(); //Coloca las fichas de los vectores en el tablero y tambien se usa para actualizar
    Tablero(int);
    void operator=(Tablero); // Para poder crear copias del tablero
    void Jugar(bool); //0 jugador 1, 1 -> jugador 2
    int BuscarFicha(vector<Ficha*>,int ,int ); //Buscar la ficha en un determinado vector por fila y columna
};
Tablero::Tablero(int Size)
{
    /*Generacion de fichas automatica*/
    int aux1=1;
    int aux2=0;
    int aux3=0;
    int aux4=1;
    tam=Size;
    Fin=0;
    for (int i=0;i<tam/2;i++)
    {
        Ficha *temp1,*temp2,*temp3,*temp4;
        temp1=new Ficha(0,tam,i+aux1,0);
        aux1++;
        temp2=new Ficha(1,tam,i+aux2,tam-1);
        aux2++;
        temp3=new Ficha(0,tam,i+aux3,1);
        aux3++;
        temp4=new Ficha(1,tam,i+aux4,tam-2);
        aux4++;
        Jugador1.push_back(temp1);
        Jugador2.push_back(temp2);
        Jugador1.push_back(temp3);
        Jugador2.push_back(temp4);
    }
    /*Generacion del tablero*/
    Tabla=new char*[tam];
    for (int i=0;i<tam;i++)
        Tabla[i]=new char[tam];
    /*Llenando el tablero con null*/
    for (int i=0;i<tam;i++)
        for(int j=0;j<tam;j++)
            Tabla[i][j]=' ';
}
void Tablero::ActulizarTablero()
{
    /*Limpiar el tablero*/
    for (int i=0;i<tam;i++)
        for(int j=0;j<tam;j++)
            Tabla[i][j]=' ';
    int aux1=Jugador1.size();
    int aux2=Jugador2.size();
    for (int i=0;i<aux1;i++)
        Tabla[Jugador1[i]->posy][Jugador1[i]->posx]=Jugador1[i]->ficha;
    for (int i=0;i<aux2;i++)
        Tabla[Jugador2[i]->posy][Jugador2[i]->posx]=Jugador2[i]->ficha;
    return;
}
void Tablero::PrintTablero()
{
    ActulizarTablero();
    for (int i=0;i<tam;i++)
    {
        for (int j=0;j<tam;j++)
            cout<<Tabla[i][j]<<"|";
        cout<<endl;
    }
    return;
}

void Tablero::operator=(Tablero A)
{
    if (tam!=A.tam) return;
/*    if (Jugador1.empty()) Jugador1.clear();
    if (Jugador2.empty()) Jugador2.clear();*/
    for (int i=0;i<tam;i++)  //De esta manera se copiara los datos para que sean independientes
    {
        *Jugador1[i]=*(A.Jugador1[i]);
        *Jugador2[i]=*(A.Jugador2[i]);
    }
    for (int i=0;i<tam;i++)
        for(int j=0;j<tam;j++)
            Tabla[i][j]=A.Tabla[i][j];
    turno=A.turno;
    tam=A.tam;
    ActulizarTablero();
}

int Tablero::BuscarFicha(vector<Ficha*>vec,int fil,int col)
{
    int i;
    for (i=0;(i<tam)&&( (vec[i]->posx!=col) || (vec[i]->posy!=fil) );i++);
    if (i==tam) i=-1;
    return i;
}
void Tablero::Jugar(bool turno)
{
    int fila,col,x,y;
    cout<<"Fila: ";
    cin>>fila;
    cout<<"Columna: ";
    cin>>col;
    cout<<"Mover a fila: ";
    cin>>y;
    cout<<"Mover a columna: ";
    cin>>x;
    int posicion;
    if ((y>=0)&&(y<tam)&&(x>=0)&&(x<tam))
    {
        if (turno==0)
        {
            posicion=BuscarFicha(Jugador1,fila,col);
            if (posicion==-1)
            {
                cout<<"ficha no encontrada";
                return;
            }
            Jugador1[posicion]->posx=x;
            Jugador1[posicion]->posy=y;
        }
        else
        {
            posicion=BuscarFicha(Jugador2,fila,col);
            if (posicion==-1)
            {
                cout<<"ficha no encontrada";
                return;
            }
            Jugador2[posicion]->posx=x;
            Jugador2[posicion]->posy=y;
        }
 //       ActulizarTablero();
        PrintTablero();
    }
    cout<<"Jugada imposible"<<endl;
    return;
}
#endif // TABLERO_H_INCLUDED
