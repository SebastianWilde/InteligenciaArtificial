#ifndef CEDGE_H_INCLUDED
#define CEDGE_H_INCLUDED
#include "CGraph.h"
#include <iostream>
using namespace std;
template <class G>
class CEdge
{
public:
    typedef typename G::B E;
    typedef typename G::Node Node;
    E n_peso;
    Node* m_nodes[2];
    bool m_dir; // 0: <-> , 1 ->
    CEdge(E pes,Node* n_1, Node* n_2, bool dir )
    {
        n_peso=pes;
        m_nodes[0]=n_1;
        m_nodes[1]=n_2;
        m_dir=dir;
    }
};

#endif // CEDGE_H_INCLUDED
