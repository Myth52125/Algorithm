#include "Graph.h"
#include <algorithm>
#include <stdio.h>
#include <iterator>
#include <set>
#include <stack>

typedef std::shared_ptr<Vertex> Vsp;
typedef std::weak_ptr<Vertex> Vwp;
typedef std::map<int,int> Vrelation;
Graph::Graph()
{
    
}
Graph::Graph(std::vector<std::vector<int>> &p)
{
    for(int i=0;i<p.size();i++)
    {
        addEdge(new Vertex(p[i][0]),new Vertex(p[i][1]));
    }
}
Graph::~Graph()
{

}

void Graph::addEdge(V *vstart,V* vend)
{
    Vsp start(vstart);
    Vsp end(vend);
    addVertex(start);
    addVertex(end);
    _vs[start->key()]->addRelation(end->key());
    _vs[end->key()]->addRelation(start->key());
}

void Graph::addVertex(Vsp &start)
{
    Vcontainer::iterator it = _vs.find(start->key());
    if(it == _vs.end())
    {
        _vs.insert({start->key(),start});
    }
}

void Graph::print()
{
    for(Vcontainer::iterator it = _vs.begin(); it != _vs.end();it++)
    {
        it->second->print();
    }
}



size_t Graph::dfs(int start,int end)
{
    std::set<int> passed;
    std::stack<int> st; 

    do
    {
        for(Vcontainer::iterator it = _vs.begin();it != _vs.end();it ++)
        {
            int tmpG = it->first;
            st.push(tmpG);
            int tmp = st.top();
            st.pop();
            Vrelation tmpVR = _vs[tmp]->relation();
            for(Vrelation::iterator itV = tmpVR.begin();itV != tmpVR.end(); itV ++)
            {
                
            }

        }
    }while(st.empty())



}
