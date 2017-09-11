#include "Vertex.h"
#include "Edge.h"
#include "Graph.h"

#include <stdio.h>
#include <vector>
using namespace std;

int main()
{

    // int i[10][2]  = {
    //     {1,2},
    //     {1,3},
    //     {1,4},
    //     {2,5},
    //     {5,6},
    //     {3,6},
    //     {6,7},
    //     {6,8},
    //     {7,9},
    //     {8,9}
    // };

    

    vector<vector<int>> i{
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
    
    printf("graph size : %d \n", g.size());
    
}