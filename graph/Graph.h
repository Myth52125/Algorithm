#ifndef _GRAPH_H_M_
#define _GRAPH_H_M_

#include <vector>
#include <Vertex.h>
#include <Graph.h>

class Graph
{
public:
    typedef Vertex<Key,Value> V;
    typedef std::vector<Vertex> VList;
    Graph()
    {}

    ~Graph()
    {}


private:
    VList _vertexs;

    void addVertex(const V *vIndex, const V *vNew)
public:
    void addEdge(Edge *edge);
    


};


#endif