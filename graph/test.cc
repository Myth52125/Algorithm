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


    Graph minpath;
    vector<vector<int>> vw{
        {1,2,3},{2,3,6},{3,5,2},{5,3,7},{5,1,3},{2,4,2},{4,2,1},{4,3,4},{1,4,5}
    };
    minpath.add(vw);
    minpath.vertex();

    cout << endl<< "----------dijkstra----------" <<endl;
    minpath.dijkstra(2,5);
    cout << endl<< "----------dijkstra----------" <<endl;


    Graph water;
    vector<vector<int>> wt{
        {1,2,16},{1,3,13},{2,3,10},{3,2,4},{2,4,12},{3,5,14},{4,3,9},{5,4,7},{4,6,20},{5,6,4}
    };
    water.add(wt);
    water.vertex();

    cout << endl<< "----------edmonds----------" <<endl;
    water.edmonds(1,6);
    cout << endl<< "----------edmonds----------" <<endl;
    
    
    
    
    cout << endl << "----------end  ----------" << endl << endl;
}