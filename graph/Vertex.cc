#include "Vertex.h"
#include <iostream>
#include <stdio.h>
#include <iterator>

Vertex::Vertex(int key)
    :_key(key)
    {

    }


void Vertex::addRelation(int key ,int w)
{
    _relationList.insert({key,w});
}

int Vertex::key()
{
    return _key;
}

void Vertex::print()
{
    printf("%d :",_key);
    for(Vrelation::iterator it = _relationList.begin();it != _relationList.end();it++)
    {
         printf("->%d ",it->first);
    }
}
