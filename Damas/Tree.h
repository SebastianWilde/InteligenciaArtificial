#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED
#include <iostream>
#include "Nodo.h"
#include <vector>
using namespace std;
class Tree
{
    public:
    int altura; //hasta que nivel crecerá el arbol
    Nodo * root;
    Tree(Tablero,int);
    bool GenerarRamas(Nodo*&,bool); //Bool que jugador creará;
    void Print();
    Nodo * minimax(Nodo*,bool,int, int); //Funcion  min max
    bool HayJugadas;
};
Tree::Tree(Tablero Tab, int h)
{
    HayJugadas=1;
    root=new Nodo(Tab);
    altura=h;
    /*Creacion del primer nivel del arbol*/
    GenerarRamas(root,0);
    if (root->hijos.empty())
    {
        HayJugadas=0;
        return;
    }
    cout<<endl<<"Ramas del primer nivel "<<root->hijos.size()<<endl;
    cout<<endl<<"--------Tablero original raiz-----------"<<endl;
    root->Tab->PrintTablero();
    cout<<endl<<"--------Tablero hijo raiz-----------"<<endl;
    for(int i=0;i<(int)root->hijos.size();i++)
    {
        root->hijos[i]->Tab->PrintTablero();
        cout<<endl;
    }
    cout<<"Tam hijos: "<<root->hijos.size();
    /*Creacion del segundo nivel*/
    for (int i=0;i<(int)root->hijos.size();i++)
    {
        GenerarRamas(root->hijos[i],1);
        cout<<endl<<"ok "<<i<<endl;
    }
}

bool Tree::GenerarRamas(Nodo * &p, bool jugador)
{
    Tablero aux(p->Tab->tam);
//    cout<<endl<<"--------Print Aux------"<<endl;
//    aux.PrintTablero();
    if (jugador==0)
    {
        for(int i=0;i<(int)p->Tab->Jugador1.size();i++)
        {
            aux=*(p->Tab);
//            cout<<endl<<"--------Print Aux------"<<endl;
//            aux.PrintTablero();
            if(aux.MoverFicha(aux.Jugador1,i,0,0)) //Si el jugador uno puede mover su ficha i a la izquierda lo agrega
            {
                cout<<endl<<"-----Tablero movido a la izquierda----"<<endl;
                aux.Jugador1[i]->Print();
//                aux.PrintTablero();
                Nodo * temp;
                temp=new Nodo(aux,jugador,i,0);
                p->hijos.push_back(temp);
            }
            aux=*(p->Tab);
            if(aux.MoverFicha(aux.Jugador1,i,1,0)) //Si el jugador uno puede mover su ficha i a la derecha lo agrega
            {
//                cout<<endl<<"-----Tablero movido a la derecha----"<<endl;
//                aux.Jugador1[i]->Print();
//                aux.PrintTablero();
                Nodo * temp2;
                temp2=new Nodo(aux,jugador,i,1);
                p->hijos.push_back(temp2);
            }
        }
    }
    else
    {
        for(int i=0;i<(int)p->Tab->Jugador2.size();i++)
        {
            aux=*(p->Tab);
            cout<<endl<<"--------Print Aux------"<<i<<endl;
            aux.PrintTablero();
            if(aux.MoverFicha(aux.Jugador2,i,0,1)) //Si el jugador dos puede mover su ficha i a la izquierda lo agrega
            {
                cout<<endl<<"-----Tablero movido a la izquierda----"<<endl;
                aux.Jugador2[i]->Print();
                Nodo * temp;
                temp=new Nodo(aux,jugador,i,0);
                p->hijos.push_back(temp);
            }
            aux=*(p->Tab);
            if(aux.MoverFicha(aux.Jugador2,i,1,1)) //Si el jugador dos puede mover su ficha i a la derecha lo agrega
            {
                cout<<endl<<"-----Tablero movido a la derecha----"<<endl;
                aux.Jugador2[i]->Print();
                Nodo * temp2;
                temp2=new Nodo(aux,jugador,i,1);
                p->hijos.push_back(temp2);
            }
        }
    }
    return 1;
}

void Tree::Print()
{
    cout<<endl<<"--------Tablero original raiz-----------"<<endl;
    root->Tab->PrintTablero();
    cout<<endl<<"--------Tablero hijo raiz-----------"<<endl;
    for(int i=0;i<(int)root->hijos.size();i++)
    {
        root->hijos[i]->Tab->PrintTablero();
        cout<<endl<<endl;
    }
    cout<<endl<<"--------Hijos de primer hijo de la raiz-----------"<<endl;
    root->hijos[0]->Tab->PrintTablero();
    cout<<endl<<endl;
    for (int i=0;i<(int)root->hijos[0]->hijos.size();i++)
    {
        root->hijos[0]->hijos[i]->Tab->PrintTablero();
        cout<<endl<<endl;
    }
}

Nodo* Tree::minimax(Nodo *nodo,bool player,int alpha, int beta)
{
    Nodo *mOpcion = new Nodo();
    if (nodo->hijos.size() == 0) {
        mOpcion = nodo;
    }
    else if (player) {
        mOpcion->heruristica = alpha;

        // Recurse for all children of node.
        //int best=nodo->Mayor();
        for (int i=0; i<(int)nodo->hijos.size(); i++) {
            Nodo *mOpcionHijo = minimax(nodo->hijos[i], false,mOpcion->heruristica,beta);
          /*  if(mOpcionHijo->heruristica > mOpcion->heruristica)
                mOpcion = mOpcionHijo;*/
        }
        int best=nodo->Mayor();
        nodo->heruristica=nodo->hijos[best]->heruristica;
        mOpcion=nodo->hijos[best];
    }
    else {
        mOpcion->heruristica = beta;

        // Recurse for all children of node.
        //int best=nodo->Menor();
        for (int i=0; i<(int)nodo->hijos.size(); i++) {
            Nodo *mOpcionHijo = minimax(nodo->hijos[i], true,alpha,mOpcion->heruristica);
         /*   if(mOpcionHijo->heruristica < mOpcion->heruristica)
                mOpcion = mOpcionHijo;*/
        }
        int best=nodo->Menor();
        nodo->heruristica=nodo->hijos[best]->heruristica;
        mOpcion=nodo->hijos[best];
    }
    return mOpcion;
}
#endif // TREE_H_INCLUDED
