#include <vector>
#include <bitset>
using namespace std;
class Genetico
{
    typedef int(*Puntero_funcion)(int);
    typedef vector<bitset<6> > Lista;
    typedef bitset<6> Bits;
    Lista poblacion;
    int Tam_Poblacion;
    int Iteraciones;
    Puntero_funcion Funcion;
    void generar_poblacion();
    Lista seleccion();
    Lista Cruzamiento(Lista X);
public:
    Lista Empezar();
    Genetico(int Tam,int Ite,Puntero_funcion Fun)
    {
        srand(time(NULL));
        Tam_Poblacion=Tam;
        Iteraciones=Ite;
        Funcion=Fun;
    }
};
void Genetico::generar_poblacion()
{
    for(int i=0;i<Tam_Poblacion;i++)
    {
        Bits num(rand()%55);
        poblacion.push_back(num);
        cout<<num<<endl;
    }
}
Genetico::Lista Genetico::seleccion()
{
    vector<float> Pre_Seleccion(Tam_Poblacion);
    vector<float> Valor_Esperado(Tam_Poblacion);
    vector<float> Valores_Funcion(Tam_Poblacion);
    Lista Vector_Cruce;
    float Sumatoria=0.0;
    for(int i=0;i<Tam_Poblacion;i++)
    {
        Valores_Funcion[i]=(*Funcion)(poblacion[i].to_ulong());
    }
    for(int i=0;i<Tam_Poblacion;i++)
    {
        Sumatoria+=Valores_Funcion[i];
    }
    float Media=Sumatoria/Tam_Poblacion;
    for(int i=0;i<Tam_Poblacion;i++)
    {
        Pre_Seleccion[i]=Valores_Funcion[i]/Sumatoria;
        Valor_Esperado[i]=Valores_Funcion[i]/Media;
    }
    for(int i=0;i<Tam_Poblacion;i++)
    {
        for(int j=0;j<roundf(Valor_Esperado[i]);j++)
        {
            Vector_Cruce.push_back(poblacion[i]);
        }
    }
    if(Vector_Cruce.size()<Tam_Poblacion)
    {
        for(int i=Vector_Cruce.size();i<Tam_Poblacion;i++)
        {
            Vector_Cruce.push_back(Vector_Cruce[0]);
        }
    }
    return Vector_Cruce;
}
Genetico::Lista Genetico::Cruzamiento(Lista X)
{
    Lista Nueva_Poblacion;
    for(int i=0;i<Tam_Poblacion;i+=2)
    {
        if(i+1<Tam_Poblacion)
        {
            int separacion=rand()%5;
            Bits temp1=X[i];
            Bits temp2=X[i+1];
            for(int j=separacion+1;j<6;j++)
            {
                int tem=temp1[j];
                temp1[j]=temp2[j];
                temp2[j]=tem;
            }
            Nueva_Poblacion.push_back(temp1);
            Nueva_Poblacion.push_back(temp2);
        }
    }
    return Nueva_Poblacion;
}
Genetico::Lista Genetico::Empezar()
{
    generar_poblacion();
    for(int i=0;i<Iteraciones;i++)
    {
        /*cout<<"Poblacion Actual"<<endl;
        for(int i=0;i<poblacion.size();i++)
        {
            cout<<poblacion[i]<<" = "<<poblacion[i].to_ulong()<<endl;
        }*/
        Lista Vector_Cruce=seleccion();
        poblacion.clear();
        poblacion=Cruzamiento(Vector_Cruce);
        long max=0;
        int maxm=0;
        for(int i=0;i<poblacion.size();i++)
        {
            int num=(*Funcion)(poblacion[i].to_ulong());
            if(max<num)
            {
                max=num;
                maxm=poblacion[i].to_ulong();
            }
        }
        cout<<"Maximo de la iteracion = "<<maxm<<endl;
    }
    return poblacion;
}
