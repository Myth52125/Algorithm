#include <Graph.h>
#include <algorithm>

Graph::Graph()
    {}


void Graph::addEdge(const Edge& e)
{
    if(e.start().lock() && e.end().lock())
    {
        addEdge(e.start().lock(),e.end().lock())
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