#include "NewGraph.h"
#include <iostream>

using namespace std;
int main()
{
    cout << endl<< "----------start----------" <<endl<< endl;

    Graph g;

    vector<vector<int>> vs{
        {4,6},{1, 2},{2,4},{4,1},{1,3},{3,4},{3,5},{5,6},
        {10,11},{11,10}
    };

    g.add(vs);

    cout << endl<< "----------findBfs----------" <<endl;
    cout<<"findBfs: "<<g.findBfs(1,6);
    cout << endl<< "----------findBfs----------" <<endl;

    
    cout << endl<< "----------dfs_re----------" <<endl;
    g.dfs_re();
    cout << endl<< "----------dfs_re----------" <<endl;

    Graph topo;
    vector<vector<int>> tp{
        {4,6},{1, 2},{2,4},{7,1},{1,3},{3,4},
        {3,5},{5,6},{8,9},{11,12}
    };
    topo.add(tp);
    topo.vertex();

    cout << endl<< "----------dfsTopo----------" <<endl;
    topo.dfsTopo();
    cout << endl<< "----------dfsTopo----------" <<endl;
    
    cout << endl<< "----------kahnTopolgical_sort----------" <<endl;
    topo.kahnTopolgical_sort();
    cout << endl<< "----------kahnTopolgical_sort----------" <<endl;

    cout << endl<< "----------ksaraju_dfs----------" <<endl;
    g.ksaraju();
    cout << endl<< "----------ksaraju_dfs----------" <<endl;
    
    cout << endl<< "----------Tarjan----------" <<endl;
    g.Tarjan();
    cout << endl<< "----------Tarjan----------" <<endl;
    
    cout << endl << "----------end  ----------" << endl << endl;
}