#ifndef CGRAPH_H_INCLUDED
#define CGRAPH_H_INCLUDED
#include <vector>
#include <iostream>
#include <list>
#include <stack>
#include <tuple>
#include <math.h>
#include "CNode.h"
#include "CEdge.h"
using namespace std;
template <class N, class E>
class CGraph
{
    public:
    typedef N A;
    typedef E B;
    typedef CGraph<N,E> self;
    typedef CNode<self> Node;
    typedef CEdge<self> Edge;
    typedef vector<Node*> NodeSet;
    typedef typename NodeSet::iterator NodoIterator;
    typedef vector<Edge*> EdgeSet;
    typedef typename EdgeSet::iterator EdgeIterator;
    NodeSet m_nodes;
    EdgeSet m_edges;
    bool Find_nodo(N, NodoIterator&);
    bool Find_edge(Node*,Node*,E, bool,EdgeIterator&);
    bool insert_nodo(N);
    bool insert_edge(E, Node*, Node*, bool);
    bool remove_edge(Node*,Node*,E, bool);
    bool remove_nodo(Node*);
    CGraph();
    bool verificar();
    vector<N> Asterisco(Node* inicio, Node* fin);
    void Ordenar(vector<vector<Node*> >& X, vector<tuple<float,float> >& Y);
    vector<N> Busqueda_profundidad(Node* inicio, Node* fin);
    //virtual ~CGraph();
};

template <class N, class E>
CGraph<N,E>::CGraph()
{
    //constructor
}


//template <class N, class E>
//CGraph<N,E>::~CGraph()
//{
//    int a=m_nodes.size();
//    for (int i=0;i<a;++i)
//        remove_nodo(m_nodes[0]);
//    //desconstructor
//}

template <class N, class E>
bool CGraph<N,E>::Find_nodo(N x, NodoIterator &i)
{
    for(i=m_nodes.begin();i!=m_nodes.end()&&(*i)->m_dato!=x;++i);
    return i!=m_nodes.end() && (*i)->m_dato==x;
}

template <class N, class E>
bool CGraph<N,E>::Find_edge(Node* n1,Node* n2,E x, bool dir,EdgeIterator& i)
{
    for(i=m_edges.begin();
    i!=m_edges.end()&&((*i)->m_nodes[0]!=n1&&(*i)->m_nodes[1]!=n2 && (*i)->n_peso!=x &&(*i)->m_dir!=dir);++i);
    return i!=m_edges.end() && (*i)->m_nodes[0]==n1&&(*i)->m_nodes[1]==n2 && (*i)->n_peso==x&&(*i)->m_dir==dir;
}

template <class N, class E>
bool CGraph<N,E>::insert_nodo(N a)
{
    NodoIterator i;
    if (Find_nodo(a,i)) return 0;
    Node * p;
    p=new Node(a);
    m_nodes.push_back(p);
    return 1;
}

template <class N, class E>
bool CGraph<N,E>::insert_edge(E b, Node* n1, Node* n2, bool di)
{
    EdgeIterator i;
    b=sqrt(pow(get<0>(n1->m_dato)-get<0>(n2->m_dato),2)+pow(get<1>(n1->m_dato)-get<1>(n2->m_dato),2));
    if (Find_edge(n1,n2,b,di,i)) return 0;
    Edge*p;
    Edge*p2;
    p=new Edge(b,n1,n2,di);
    p2=new Edge(b,n2,n1,di);
    n1->m_edges.push_back(p);
    n2->m_edges.push_back(p2);
    m_edges.push_back(p);
    return 1;
}

template <class N, class E>
bool CGraph<N,E>::remove_edge(Node* n1,Node* n2,E b,bool a)
{
    EdgeIterator i;
    if(!Find_edge(n1,n2,b,a,i)) return 0;
    Edge * temp1, *temp2;
    temp1=temp2=*i;
//    cout<<temp1->n_peso<<endl<<temp2->n_peso<<endl;
    (*i)->m_nodes[0]->Remove_edge(temp1);
    (*i)->m_nodes[1]->Remove_edge(temp2);
//    cout<<(*i)->n_peso;
    //borrar nodos
    delete *i;
    delete temp1;
    delete temp2;
    m_edges.erase(i);
    return 1;
}

template <class N, class E>
bool CGraph<N,E>::remove_nodo(Node* n)
{
    cout<<endl<<n->m_dato<<endl;
    NodoIterator i;
    if (!Find_nodo(n->m_dato,i)) return 0;
//    EdgeIterator j;
    int a=n->m_edges.size();
    for (int i=0;i<a;++i)
        remove_edge(n,n->m_edges[i]->m_nodes[1],m_edges[i]->n_peso,m_edges[i]->m_dir);
//    delete *j;
    m_nodes.erase(i);
    return 1;
}

template <class N, class E>
bool CGraph<N,E>::verificar()
{
    int tam_nod_vec=m_nodes.size();
    int cont=0;
    int cont2=0;
    for (int i=0;i<tam_nod_vec;++i)
    {
        cout<<get<0> (m_nodes[i]->m_dato)<<" sus aristas son "<<m_nodes[i]->m_edges.size()<<endl;
        if((m_nodes[i]->m_edges.size())%2!=0)
            cont+=1;
        else
            cont2+=1;
    }
    if (cont==2) return 1;
    else if (cont2==m_nodes.size()) return 1;
    return 0;
}

template <class N, class E>
void CGraph<N,E>::Ordenar(vector<vector<Node*> >& X, vector<tuple<float,float> >& Y)
{
    int j;
    N temp;
    vector<Node*> temp2;
	for (int i = 0; i < Y.size(); i++)
    {
		j = i;
		while (j > 0 && get<0>(Y[j])+get<1>(Y[j]) < get<0>(Y[j-1])+get<1>(Y[j-1]))
		{
            temp = Y[j];
            Y[j] = Y[j-1];
            Y[j-1] = temp;
            temp2= X[j];
            X[j] = X[j-1];
            X[j-1] = temp2;
            j--;
        }
    }
}

template <class N, class E>
vector<N> CGraph<N,E>::Asterisco(Node* inicio,Node* fin)
{
    vector<vector<Node*> > Resp;
    vector<tuple<float,float> > Calculos;
    vector<Node*> pri;
    pri.push_back(inicio);
    tuple<float,float> dist(0,sqrt(pow(get<0>(inicio->m_dato)-get<0>(fin->m_dato),2)+pow(get<1>(inicio->m_dato)-get<1>(fin->m_dato),2)));
    Calculos.push_back(dist);
    Resp.push_back(pri);
    Node* uso=inicio;
    while(uso!=fin)
    {
        for(int i=0;i<Calculos.size();i++)
        {
            cout<<"("<<get<0>(Calculos[i])<<","<<get<1>(Calculos[i])<<")"<<";";
        }
        cout<<endl;
        vector<Node*> tem (Resp[0]);
        for(int i=0;i < uso->m_edges.size();i++)
        {
            Edge* nuevo = uso->m_edges[i];
            tem.push_back(nuevo->m_nodes[1]);
            get<0> (dist) = get<0>(Calculos[0])+nuevo->n_peso;
            get<1> (dist) = sqrt(pow(get<0>(nuevo->m_nodes[1]->m_dato)-get<0>(fin->m_dato),2)+pow(get<1>(nuevo->m_nodes[1]->m_dato)-get<1>(fin->m_dato),2));
            Resp.push_back(tem);
            Calculos.push_back(dist);
            tem.pop_back();
        }
        Resp.erase(Resp.begin());
        Calculos.erase(Calculos.begin());
        Ordenar(Resp,Calculos);
        uso=Resp[0].back();
    }
    vector<N> Camino;
    for(int i=0;i<Resp[0].size();i++)
    {
        Camino.push_back(Resp[0][i]->m_dato);
    }
    return Camino;
}

template <class N, class E>
vector<N> CGraph<N,E>::Busqueda_profundidad(Node* inicio, Node* fin)
{
    stack<Node*> porevaluar;
    vector<N> visitados;
    porevaluar.push(inicio);
    while(!porevaluar.empty())
    {
        auto aux = porevaluar.top();
        aux->visitado = 1;
        porevaluar.pop();
        visitados.push_back(aux->m_dato);
        if(aux->m_dato == fin->m_dato)
            return visitados;
        EdgeIterator j;
        for (j=aux->m_edges.begin();j!=aux->m_edges.end();++j)
        {
            if (!(j!=aux->m_edges.end())) return visitados;
            if(!(*j)->m_nodes[1]->visitado)
                porevaluar.push((*j)->m_nodes[1]);
        }
    }
    return visitados;
}


#endif // CGRAPH_H_INCLUDED
