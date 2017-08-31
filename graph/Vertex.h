#ifndef _VERTEX_H_M_
#define _VERTEX_H_M_


template <typename Key,typename Value> 
class Vertex
{
public:
    Vertex(Key key)
        :_key(key),_value(Value())
        {}

    ~Vertex();

    Key _key;
    Value _value;
    Vertex *_next;

};



#endif