#include <iostream>
#include "CGraph.h"
#include <vector>
using namespace std;

int main()
{
    CGraph<char,int>a;
    a.insert_nodo('A');
    a.insert_nodo('B');
    a.insert_nodo('C');
    a.insert_nodo('D');
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
    cout << "Hello world!" << endl;
    return 0;
}
