#ifndef _VERTEX_H_M_
#define _VERTEX_H_M_

#include <memory>
#include <stdio.h>
#include <map>

class Vertex
{
public:
    typedef std::map<int,int> Vrelation;
    Vertex(int key);
private:
    int _key;
    Vrelation _relationList;
    
public:
    void addRelation(int key,int w=1);
    int key();
    Vrelation &relation();
    void print();
    
};




#endif