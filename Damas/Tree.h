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
    Nodo* minimax(Nodo*,bool);
    void Print();
};
Tree::Tree(Tablero Tab, int h)
{
    root=new Nodo(Tab);
    altura=h;
    /*Creacion del primer nivel del arbol*/
    GenerarRamas(root,0);

    /*cout<<endl<<"Ramas del primer nivel "<<root->hijos.size()<<endl;
    cout<<endl<<"--------Tablero original raiz-----------"<<endl;
    root->Tab->PrintTablero();
    cout<<endl<<"--------Tablero hijo raiz-----------"<<endl;
    for(int i=0;i<(int)root->hijos.size();i++)
    {
        root->hijos[i]->Tab->PrintTablero();
        cout<<endl;
    }*/

    /*Creacion del segundo nivel*/
    for (int i=0;i<(int)root->hijos.size();i++)
    {
        GenerarRamas(root->hijos[i],1);
        //cout<<endl<<"ok "<<i<<endl;
    }
}

Nodo* Tree::minimax(Nodo *nodo,bool player)
{
    Nodo *mOpcion = new Nodo();
    if (nodo->hijos.size() == 0) {
        mOpcion = nodo;
    }
    else if (player) {
        mOpcion->heruristica = -1;

        // Recurse for all children of node.
        for (int i=0, c=nodo->hijos.size(); i<c; i++) {
            Nodo *mOpcionHijo = minimax(nodo->hijos[i], false);
            if(mOpcionHijo->heruristica > mOpcion->heruristica)
                mOpcion = mOpcionHijo;
        }
    }
    else {
        mOpcion->heruristica = 1;

        // Recurse for all children of node.
        for (int i=0, c=nodo->hijos.size(); i<c; i++) {
            Nodo *mOpcionHijo = minimax(nodo->hijos[i], true);
            if(mOpcionHijo->heruristica < mOpcion->heruristica)
                mOpcion = mOpcionHijo;
        }
    }
    return mOpcion;
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
            //aux.Jugador1[i]->Print();
            if(aux.MoverFicha(aux.Jugador1,i,0,0)) //Si el jugador uno puede mover su ficha i a la izquierda lo agrega
            {
//                cout<<endl<<"-----Tablero movido a la izquierda----"<<endl;
//                aux.PrintTablero();
                Nodo * temp;
                temp=new Nodo(aux,0,i,0);
                p->hijos.push_back(temp);
            }
            aux=*(p->Tab);
            if(aux.MoverFicha(aux.Jugador1,i,1,0)) //Si el jugador uno puede mover su ficha i a la derecha lo agrega
            {
//                cout<<endl<<"-----Tablero movido a la derecha----"<<endl;
//                aux.PrintTablero();
                Nodo * temp2;
                temp2=new Nodo(aux,0,i,1);
                p->hijos.push_back(temp2);
            }
        }
    }
    else
    {
        for(int i=0;i<(int)p->Tab->Jugador2.size();i++)
        {
            aux=*(p->Tab);
            if(aux.MoverFicha(aux.Jugador2,i,0,1)) //Si el jugador dos puede mover su ficha i a la izquierda lo agrega
            {
                Nodo * temp;
                temp=new Nodo(aux,1,i,0);
                p->hijos.push_back(temp);
            }
            aux=*(p->Tab);
            if(aux.MoverFicha(aux.Jugador2,i,1,1)) //Si el jugador dos puede mover su ficha i a la derecha lo agrega
            {
                Nodo * temp2;
                temp2=new Nodo(aux,1,i,1);
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
    cout<<endl<<"--------Hijos de -----------"<<endl;
    root->hijos[0]->Tab->PrintTablero();
    cout<<endl<<endl;
    for (int i=0;i<(int)root->hijos[0]->hijos.size();i++)
    {
        root->hijos[0]->hijos[i]->Tab->PrintTablero();
        cout<<endl<<endl;
    }
}

#endif // TREE_H_INCLUDED
