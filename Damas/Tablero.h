#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED
#include <iostream>
#include "Ficha.h"
#include <string>
#include <stdlib.h>
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
    void Jugar(bool&); //0 jugador 1, 1 -> jugador 2
    int BuscarFicha(vector<Ficha*>,int ,int ); //Buscar la ficha en un determinado vector por fila y columna
    bool MoverFicha(vector<Ficha*>,int,bool,bool);//Mover ficha, iteracion de ficha, izquierda 0,derecha 1, 0->jugador1
                                                //1->jugador2
    bool EndGame();
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
    cout<<endl;
    cout<<"0|1|2|3|4|5|"<<endl;
    cout<<"------------"<<endl;
    for (int i=0;i<tam;i++)
    {
        for (int j=0;j<tam;j++)
            cout<<Tabla[i][j]<<"|";
        cout<<" "<<i<<endl;
    }
    return;
}

void Tablero::operator=(Tablero A)
{
    if (tam!=A.tam) return;
/*    if (Jugador1.empty()) Jugador1.clear();
    if (Jugador2.empty()) Jugador2.clear();*/
   /* for (int i=0;i<tam;i++)  //De esta manera se copiara los datos para que sean independientes
    {
        *Jugador1[i]=*(A.Jugador1[i]);
        *Jugador2[i]=*(A.Jugador2[i]);
    }*/
    for (int i=0;i<(int)A.Jugador1.size();i++) *Jugador1[i]=*(A.Jugador1[i]);
    for (int i=0;i<(int)A.Jugador2.size();i++) *Jugador2[i]=*(A.Jugador2[i]);
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
    for (i=0;(i<(int)vec.size())&&( (vec[i]->posx!=col) || (vec[i]->posy!=fil) );i++);
    if (i==(int)vec.size()) i=-1;
    return i;
}
bool Tablero::MoverFicha(vector<Ficha*>vec,int i, bool movida,bool jugador)
{
    int direccion,sentido; //direccion->si se mueve hacia abajo o hacia arriba || sentido izquierda o derecha
    if (jugador==0) direccion=1; //La ficha se mueve hacia abajo
    else direccion=-1;
    if (movida==0) sentido=-1; //La ficha se mueve hacia la derecha
    else sentido=1;
    int new_x=vec[i]->posx+(1*sentido);
    int new_y=vec[i]->posy+(1*direccion);
//    cout<<endl<<new_x<<" "<<new_y<<endl;
        if (!((new_y>=0)&&(new_y<tam)&&(new_x>=0)&&(new_x<tam))
            || Tabla[new_y][new_x]==vec[i]->ficha)//Si se sale del tablero o ya hay una ficha suya ahi
        {
        //cout<<endl<<"Fuera del tablero o posicion ocupada - "<<"Jugada imposible"<<endl;
        return 0;
        }
        if(Tabla[new_y][new_x]!=' ')
        {
            int new_x_2=vec[i]->posx+(2*sentido);
            int new_y_2=vec[i]->posy+(2*direccion);
            if (!((new_y_2>=0)&&(new_y_2<tam)&&(new_x_2>=0)&&(new_x_2<tam))
                || Tabla[new_y_2][new_x_2]!=' ') //Si al comer ficha se sale de tablero o hay dos fichas enemigas juntas
            {
                //cout<<"Jugada imposible"<<endl;
                return 0;
            }
            else
            {
                int aux;//Para localizar la ficha que sera eliminada
                if(jugador==0)
                {
                    aux=BuscarFicha(Jugador2,new_y,new_x);
                    Jugador2.erase(Jugador2.begin()+aux);
                }
                else
                {
                    aux=BuscarFicha(Jugador1,new_y,new_x);
                    Jugador1.erase(Jugador1.begin()+aux);
                }
                vec[i]->posx=new_x_2;
                vec[i]->posy=new_y_2;
                return 1;
            }
        }
        vec[i]->posx=new_x;
        vec[i]->posy=new_y;
        return 1;
}
#include "Tree.h"
void Tablero::Jugar(bool &turno)
{
    if (turno==0)/*Aqui viene el turno de la maquina*/
    {
        Tree Aux(*this,tam);
//      Aux.Print(); //Quitar cometario para ver el primer nivel del arbol
        if (Aux.HayJugadas==0)
        {
            Fin=1;
            cout<<endl<<"Fin del juego, ganador jugador 1"<<endl;
            return;
        }
        Nodo* temp=Aux.minimax(Aux.root,!turno,-100,100);
       /* posicion=BuscarFicha(Jugador1,fila,col);
        if (posicion==-1)
        {
            cout<<"ficha no encontrada";
            return;
        }*/
        if(MoverFicha(Jugador1,temp->Who_move,temp->where_move,turno)==0)
        {
            cout<<endl<<"Jugada imposible"<<endl;
            return;
        }
    }
    else /*Turno del jugador*/
    {
        int fila,col;
        bool mov;
        cout<<"Fila: ";
        cin>>fila;
        cout<<"Columna: ";
        cin>>col;
        cout<<"0) Izquierda" << endl<<"1) Derecha"<<endl;
        cin>>mov;
        int posicion;
        posicion=BuscarFicha(Jugador2,fila,col);
        if (posicion==-1)
        {
            cout<<"ficha no encontrada";
            return;
        }
        if (MoverFicha(Jugador2,posicion,mov,turno)==0)
        {
            cout<<endl<<"Jugada imposible"<<endl;
            return;
        }
    }
    turno^=1; /*Para que se cambie de turno ^ : es un XOR*/
    if(Jugador1.size()==0 || Jugador2.size()==0) Fin=1;
    if(EndGame()) Fin=1;
    if(Fin==1) return;
    system("cls");
    PrintTablero();
    return;
}
bool Tablero::EndGame()
{
    for (int i=0;i<(int)Jugador1.size();i++)
        if (Jugador1[i]->posy==tam-1) return 1;
    for (int i=0;i<(int)Jugador2.size();i++)
        if (Jugador2[i]->posy==0) return 1;
    return 0;
}
#endif // TABLERO_H_INCLUDED
