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
    Vrelation _out;
    Vrelation _in;
    
public:
    void addOut(int key,int w=1);
    void addIn(int key,int w=1);
    int key();
    Vrelation &out();
    Vrelation &in();
    void print();
    
};

#endif