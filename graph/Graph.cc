#include "Graph.h"
#include <algorithm>
#include <stdio.h>

Graph::Graph()
    {
        printf("Graph cst \n");
        
    }


void Graph::addEdge(const Edge& e)
{
    if(e->start().lock() && e->end().lock())
    {
        addEdge(e->start().lock(),e->end().lock())
    }
}

void Graph::addVertex(Vsp start,Vsp end)
{
        Vsp vspTmp(start);
        Vsp tmp = _next[start->key()];
        if(tmp = NULL)
        {
            vspTmp->next(v);
            _next[start->key()]=vspTmp;            
        }


}