#ifndef _VERTEX_H_M_
#define _VERTEX_H_M_

#include <string>
#include <memory>
#include <iostream>
using namespace std;

class Vertex
{
public:
    
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
    std::weak_ptr<Vertex> _next;
    
public:
    std::weak_ptr<Vertex> &next()
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

    void next(std::shared_ptr<Vertex>  &v)
    {
        

        if(_next.lock())
        {
            std::weak_ptr<Vertex> tmp(_next);

            while(tmp.lock())
            {
                tmp = tmp.lock()->next();
            }
            tmp = v;
        }else{
            _next = v;
        }
    }
    
};



#endif