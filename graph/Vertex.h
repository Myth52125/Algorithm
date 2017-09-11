#ifndef _VERTEX_H_M_
#define _VERTEX_H_M_

#include <string>
#include <memory>
using namespace std;

class Vertex
{
public:
    
    explicit Vertex(int key, string value = "")
        :_key(key),_value(value)
        {
            printf("Vertex cst \n");
        }
    ~Vertex()
    {
        printf("Vertex des \n");        
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
    void next(std::shared_ptr<Vertex>  v)
    {
        _next = v;
    }
};



#endif