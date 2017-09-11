#ifndef _GRAPH_H_M_
#define _GRAPH_H_M_

#include <vector>
#include <Vertex.h>
#include <Graph.h>
#include <map>

class Graph
{
public:
    typedef std::shared_ptr<Vertex> Vsp;
    typedef std::weak_ptr<Vertex> Vwp;
   
    typedef std::map<int ,shared_ptr<Vertex>> VertexList;
    
    Graph();

private:
    VertexList _list;
    
    void addVertex(Vsp start,Vsp end);
public:
    void addEdge(const Edge& e);
    

};


#endif