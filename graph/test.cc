#include "NewGraph.h"
#include <iostream>

using namespace std;
int main()
{
    cout << endl
         << "----------start----------" << endl
         << endl;

    Graph g;

    vector<vector<int>> vs{
        {1, 2},{2,1}
    };

    g.add(vs);

    cout << endl
         << "----------end  ----------" << endl
         << endl;
}