#ifndef _VERTEX_H_M_
#define _VERTEX_H_M_

#include <string>
using namespace std;

class Vertex
{
public:
    typedef std::weak_ptr<Vertex> Vwp;
    typedef std::shared_ptr<Vertex> Vsp;
    
    explicit Vertex(int key, string value = "")
        :_key(key),_value(value)
        {}

private:
    int _key;
    string _value;
    Vwp _next;
    
public:
    Vwp &next()
    {
        return _next;
    }
    int key()
    {
        return _key;
    }
    int value()
    {
        return _value;
    }
    void value(Vsp v)
    {
        _next = v;
    }
};



#endif