#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"

#include <stdio.h>
#include <vector>


int main()
{
    std::vector<std::vector<int>> i{
        {1,2},
        {1,3},
        {1,4},
        {2,5},
        {5,6},
        {3,6},
        {4,7},
        {4,6},
        {4,9},
        {2,9},
        {9,7},
        {7,8},
        {8,9}
    };
    Graph g(i);
    g.print();
    
}