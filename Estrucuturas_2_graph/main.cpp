#include <iostream>
#include "CGraph.h"
#include <vector>
#include <tuple>
using namespace std;

int main()
{
    CGraph<tuple<int,int>,int> a;
    tuple<int,int> a1 (1,2);
    tuple<int,int> b (2,2);
    tuple<int,int> c (3,5);
    tuple<int,int> d (6,7);
    a.insert_nodo(a1);
    a.insert_nodo(b);
    a.insert_nodo(c);
    a.insert_nodo(d);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[1],0);
    a.insert_edge(3,a.m_nodes[1],a.m_nodes[2],0);
    a.insert_edge(3,a.m_nodes[2],a.m_nodes[3],0);
    a.insert_edge(3,a.m_nodes[3],a.m_nodes[0],0);
    a.insert_edge(3,a.m_nodes[0],a.m_nodes[2],0);
    a.insert_edge(3,a.m_nodes[1],a.m_nodes[3],0);

//    cout<<"Puede dibujarse? "<<a.verificar()<<endl;
//    a.remove_edge(a.m_nodes[0],a.m_nodes[1],3,0);
//    a.remove_nodo(a.m_nodes[0]);
   // a.insert_edge(3,a.m_nodes[1],a.m_nodes[3],0);
    cout<<"Puede dibujarse? "<<a.verificar()<<endl;
//    a.remove_nodo(a.m_nodes[1]);
    //cout<<a.m_nodes[0]->m_dato<<" "<<a.m_nodes[1]->m_dato<<" ";//<< a.m_edges.back()->n_peso;
    return 0;
}
