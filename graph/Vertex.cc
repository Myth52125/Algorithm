#include "Vertex.h"
#include <iostream>
#include <stdio.h>
#include <iterator>
typedef std::map<int,int> Vrelation;

Vertex::Vertex(int key)
    :_key(key)
    {

    }


void Vertex::addOut(int key ,int w)
{
    _out.insert({key,w});
}

void Vertex::addIn(int key ,int w)
{
    _in.insert({key,w});
}

int Vertex::key()
{
    return _key;
}

void Vertex::print()
{
    printf("%d (size %d):",_key,_out.size());
    for(Vrelation::iterator it = _out.begin();it != _out.end();it++)
    {
         printf("->%d ",it->first);
    }
    printf("\n");
    
}

Vrelation &Vertex::out()
{
    return _out;
}

Vrelation &Vertex::in()
{
    return _in;
}