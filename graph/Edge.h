#ifndef _EDGE_H_M_
#define _EDGE_H_M_

#include "Vertex.h"
#include <memory>
#include <stdio.h>
class Edge
{
public:
   
    Edge(Vertex *v1 ,Vertex *v2,int weight = 1,bool direction= false)
        :_v1(v1),_v2(v2),
        _weight(weight),_direction(direction)
        {
        }
    ~Edge()
    {
    }
private:
    std::shared_ptr<Vertex> _v1;
    std::shared_ptr<Vertex> _v2;
    int _weight;
    bool _direction;

public:
    std::shared_ptr<Vertex> &start()
    {
        return _v1;
    }

    std::shared_ptr<Vertex> &end()
    {
        return _v2;
    }


};




#endif