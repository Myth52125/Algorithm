#ifndef _GRAPH_H_M_
#define _GRAPH_H_M_

#include <vector>
#include "Vertex.h"
#include "Graph.h"
#include "Edge.h"
#include <map>

class Graph
{
public:
    typedef std::map<int ,shared_ptr<Vertex>> VertexList;
    
    Graph();

private:
    VertexList _list;
    
    void addVertex(std::shared_ptr<Vertex> start,std::shared_ptr<Vertex> end);
public:
    void addEdge(const Edge& e);
    

};


#endif