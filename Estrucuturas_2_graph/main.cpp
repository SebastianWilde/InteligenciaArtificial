#include <iostream>
#include "CGraph.h"
#include <vector>
#include "CNode.h"
#include <tuple>
using namespace std;

int main()
{
    /*
    CGraph<tuple<int,int>,float> a;
    tuple<int,int> p0 (3,8);
    tuple<int,int> p1 (3,4);
    tuple<int,int> p2 (4,9);
    tuple<int,int> p3 (5,10);
    tuple<int,int> p4 (5,3);
    tuple<int,int> p5 (5,2);
    tuple<int,int> p6 (5,1);
    tuple<int,int> p7 (9,1);
    tuple<int,int> p8 (8,5);
    tuple<int,int> p9 (7,7);
    tuple<int,int> p10 (11,4);
    tuple<int,int> p11 (10,7);
    tuple<int,int> p12 (14,3);
    a.insert_nodo(p0);
    a.insert_nodo(p1);
    a.insert_nodo(p2);
    a.insert_nodo(p3);
    a.insert_nodo(p4);
    a.insert_nodo(p5);
    a.insert_nodo(p6);
    a.insert_nodo(p7);
    a.insert_nodo(p8);
    a.insert_nodo(p9);
    a.insert_nodo(p10);
    a.insert_nodo(p11);
    a.insert_nodo(p12);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[1],0);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[2],0);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[9],0);
    a.insert_edge(3,a.m_nodes[1],a.m_nodes[4],0);
    a.insert_edge(3,a.m_nodes[4],a.m_nodes[5],0);
    a.insert_edge(3,a.m_nodes[5],a.m_nodes[6],0);
    a.insert_edge(3,a.m_nodes[6],a.m_nodes[7],0);
    a.insert_edge(3,a.m_nodes[7],a.m_nodes[8],0);
    a.insert_edge(3,a.m_nodes[7],a.m_nodes[10],0);
    a.insert_edge(3,a.m_nodes[9],a.m_nodes[8],0);
    a.insert_edge(3,a.m_nodes[2],a.m_nodes[3],0);
    a.insert_edge(3,a.m_nodes[9],a.m_nodes[11],0);
    a.insert_edge(3,a.m_nodes[10],a.m_nodes[8],0);
    a.insert_edge(3,a.m_nodes[10],a.m_nodes[12],0);

    vector<tuple<int,int> > Res=a.Asterisco(a.m_nodes[0],a.m_nodes[12]);
    for(int i=0;i<Res.size();i++)
    {
        cout<<"("<<get<0>(Res[i])<<","<<get<1>(Res[i])<<")"<<";";
    }
    */
    CGraph<tuple<int,int>,float> a;
    tuple<int,int> p0 (0,8);
    tuple<int,int> p1 (1,4);
    tuple<int,int> p2 (2,9);
    tuple<int,int> p3 (3,10);
    tuple<int,int> p4 (4,3);
    tuple<int,int> p5 (5,2);
    tuple<int,int> p6 (6,1);
    tuple<int,int> p7 (7,1);
    tuple<int,int> p8 (8,5);
    tuple<int,int> p9 (9,7);
    tuple<int,int> p10 (10,4);
    tuple<int,int> p11 (11,7);
    tuple<int,int> p12 (12,3);
    a.insert_nodo(p0);
    a.insert_nodo(p1);
    a.insert_nodo(p2);
    a.insert_nodo(p3);
    a.insert_nodo(p4);
    a.insert_nodo(p5);
    a.insert_nodo(p6);
    a.insert_nodo(p7);
    a.insert_nodo(p8);
    a.insert_nodo(p9);
    a.insert_nodo(p10);
    a.insert_nodo(p11);
    a.insert_nodo(p12);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[1],0);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[2],0);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[9],0);
    a.insert_edge(3,a.m_nodes[1],a.m_nodes[4],0);
    a.insert_edge(3,a.m_nodes[4],a.m_nodes[5],0);
    a.insert_edge(3,a.m_nodes[5],a.m_nodes[6],0);
    a.insert_edge(3,a.m_nodes[6],a.m_nodes[7],0);
    a.insert_edge(3,a.m_nodes[7],a.m_nodes[8],0);
    a.insert_edge(3,a.m_nodes[7],a.m_nodes[10],0);
    a.insert_edge(3,a.m_nodes[9],a.m_nodes[8],0);
    a.insert_edge(3,a.m_nodes[2],a.m_nodes[3],0);
    a.insert_edge(3,a.m_nodes[9],a.m_nodes[11],0);
    a.insert_edge(3,a.m_nodes[10],a.m_nodes[8],0);
    a.insert_edge(3,a.m_nodes[10],a.m_nodes[12],0);

    auto Res=a.Busqueda_profundidad(a.m_nodes[0],a.m_nodes[12]);
    for(int i=0;i<Res.size();i++)
    {
        cout<<"("<<get<0>(Res[i])<<","<<get<1>(Res[i])<<")"<<";"<<endl;
    }
    return 0;


}
