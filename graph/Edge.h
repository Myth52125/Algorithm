#ifndef _EDGE_H_M_
#define _EDGE_H_M_

#include "Vertex.h"
#include <memory>
#include <stdio.h>
class Edge
{
public:
    typedef Vertex V;
    
    Edge(Vertex *v1 ,Vertex *v2,int weight = 1,bool direction= false)
        :_v1(v1),_v2(v2),
        _weight(weight),_direction(direction)
        {
            printf("Edge::v1: %d %p ,v2  %d %p ",_v1->key(),_v1.get(),_v2->key(),_v2.get());        
        }
    ~Edge()
    {
        printf("            Edge des \n");
        
    }
private:
    std::shared_ptr<Vertex> _v1;
    std::shared_ptr<Vertex> _v2;
    int _weight;
    bool _direction;

public:
    V &start()
    {
        return *_v1;
    }

    V &end()
    {
        
        return *_v2;
    }


};




#endif