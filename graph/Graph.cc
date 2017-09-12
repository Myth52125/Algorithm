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
    int steps{0};
    bool pushed{false};
    std::map<int,int> father;

    st.push(start);
    passed.insert(start);
    do
    {
            int tmp = st.top();
            //处理该节点
            if(tmp == end)
            {
                return 1;
                break;
            }
            //处理完毕
            st.pop();
            steps--;
            Vrelation tmpVR = _vs[tmp]->relation();
            for(Vrelation::iterator itV = tmpVR.begin();itV != tmpVR.end(); itV ++)
            {
               int tmpV = itV->first;
            
               if(passed.find(tmpV) == passed.end())
               {
                     father[tmpV]=tmp;
                    st.push(tmpV);
                    passed.insert(tmpV);
                    pushed = true;
               } 
            }

          //  printf("set size : %dpath \n",st.size());
            
    }while(!st.empty());

    // std::vector<int> path;
    // path.push_back(end);

    // for (int i = end ; i != start;i=father[i])
    // {
    //     path.push_back(father[i]);    
    // }
    // printf("path:");

    // for(int i = path.size()-1;i>=0;i--)
    // {   
    //     printf(" %d ",path[i]);
    // }
    // printf("\n");
    
    return -1;
}
