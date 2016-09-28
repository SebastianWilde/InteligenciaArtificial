#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
#include "Genetico.h"
using namespace std;
int Funcion(int X)
{
    return -((X-30)*(X-30))/50+20;
}
int main()
{
    Genetico Prueba(4,30,Funcion);
    vector<bitset<6> > Ultima_Poblacion=Prueba.Empezar();
    /*for(int i=0;i<Ultima_Poblacion.size();i++)
        cout<<Ultima_Poblacion[i].to_ulong()<<endl;*/
    return 0;
}
