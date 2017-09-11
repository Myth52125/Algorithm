#ifndef _VERTEX_H_M_
#define _VERTEX_H_M_

#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Vertex
{
public:
    typedef std::shared_ptr<Vertex> Vsp;
    typedef std::weak_ptr<Vertex> Vwp;
    
    explicit Vertex(int key, string value = "")
        :_key(key),_value(value),_next()
        {
        }
    ~Vertex()
    {
    }
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
    string value()
    {
        return _value;
    }

    void next(Vsp  &v)
    {
        if(_next.lock())
        {
            Vwp tmp(_next);
            while(tmp.lock())
            {
                if(tmp.lock()->key() != v->key())
                {
                    tmp = tmp.lock()->next();
                }else{
                    return;
                }
            }
            tmp = v;
        }else{
            _next = v;
        }
    }

    
};



#endif