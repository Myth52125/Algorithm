#ifndef _EDGE_H_M_
#define _EDGE_H_M_




template<typename Key,typename Value>
class Edge
{
public:
    typedef Vertex<Key,Value> V;

    Edge(V start, V end, int weight = 1, bool direct = false)
        :_start(start),_end(end),
        _weight(weight),_direct(direct)
        {}
private:
    V _start;
    V _end;
    bool _direct;
    int weight;
public:
    const V &start();
    
};




#endif