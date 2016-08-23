#ifndef CGRAPH_H_INCLUDED
#define CGRAPH_H_INCLUDED
#include <vector>
#include <iostream>
#include <list>
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
    virtual ~CGraph();
};

template <class N, class E>
CGraph<N,E>::CGraph()
{
    //constructor
}


template <class N, class E>
CGraph<N,E>::~CGraph()
{
   /* int a=m_nodes.size();
    for (int i=0;i<a;++i)
        remove_nodo(m_nodes[0]);
    //desconstructor
    */
}

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
    if (Find_edge(n1,n2,b,di,i)) return 0;
    Edge*p;
    p=new Edge(b,n1,n2,di);
    n1->m_edges.push_back(p);
    n2->m_edges.push_back(p);
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
        cout<<m_nodes[i]->m_dato<<" sus aristas son "<<m_nodes[i]->m_edges.size()<<endl;
        if((m_nodes[i]->m_edges.size())%2!=0)
            cont+=1;
        else
            cont2+=1;
    }
    if (cont==2) return 1;
    else if (cont2==m_nodes.size()) return 1;
    return 0;
}
#endif // CGRAPH_H_INCLUDED
