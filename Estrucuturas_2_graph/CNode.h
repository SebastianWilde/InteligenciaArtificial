#ifndef CNODE_H_INCLUDED
#define CNODE_H_INCLUDED
#include "CGraph.h"
#include <list>
#include <vector>
#include <iostream>
using namespace std;
template <class G>
class CNode
{
public:
    typedef typename G::A N;
    typedef typename G::Edge Edge;
    typedef typename G::EdgeSet::iterator EdgeIterator;
    N m_dato;
    bool visitado;
    vector<Edge*> m_edges;
    CNode(N dat){
        m_dato=dat;
    }
    bool Remove_edge(Edge*);

};

template <class G>
bool CNode<G>::Remove_edge(Edge* e)
{

    EdgeIterator i;
    for (i=m_edges.begin();i!=m_edges.end()&&(*i)!=e;++i);
    if (!(i!=m_edges.end())) return 0;
    m_edges.erase(i);
    return 1;
}

#endif // CNODE_H_INCLUDED
