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
    typedef std::shared_ptr<Vertex> Vsp;
    typedef std::weak_ptr<Vertex> Vwp;
    
    Graph();
    Graph(vector<vector<int>> &);    
    ~Graph();
private:
    VertexList _list;
    
    void addVertex(Vsp &start,Vsp &end);
public:
    void addEdge(Edge& e);
    size_t size()  const;
    
};


#endif