#ifndef _EDGE_H_M_
#define _EDGE_H_M_

#include <Vertex.h>
#include <memory>

class Edge
{
public:
    typedef std::shared_ptr<Vertex> Vsp;
    typedef std::weak_ptr<Vertex> Vwp;
    
    Edge(Vsp v1 ,Vsp v2,int weight = 1,bool direction= false)
        :_v1(v1),_v2(v2),
        _weight(weight),_direction(direction)
        {}

private:
    Vwp _v1;
    Vwp _v2;
    int _weight;
    bool _direction;

public:
    Vwp &start()
    {
        return _v1;
    }

    Vwp &end()
    {
        return _v2;
    }


};




#endif