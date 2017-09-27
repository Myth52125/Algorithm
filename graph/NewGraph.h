#include <vector>
#include <deque>
#include <stack>
using namespace std;

struct Node
{
    int lkey;
    Node *to;
    //为广度优先搜索添加的，距离，父节点
    int d;
    int p;
    //为深度优先搜索记录的发现时间和处理结束时间
    int reach;
    int leave;
};

class Graph
{
  public:
    Graph();

  private:
    vector<Node *> vContainer;

    void dfs_re_func(int curKey, vector<int> &memo);
    void dfsTopo_func(int curKey, vector<int> &result ,vector<bool> &memo );
    void ksaraju_dfs(int curKey,vector<int> &memo,vector<int> &scc,&vContainer);    
    void ksaraju_calOrder(vector<Node*> &vContainer,&vector<int> order);
    void ksaraju_reverse(vector<Node *> &oldG,vector<Node*> &newG);
    void Tarjan_dfs(Node * n,int &reachTime;vector<int> &reach,vector<int> &low,vector<int> &flag,deque<int> &st);
    
  public:
    int findBfs(int start, int end);
    int findBfs_re(int start, int end);

    int dfs_re(int start);
    vector<int> dfsTopo();
    void kahnTopolgical_sort();
    void dfs(int curKey, int &time ,vector<bool> &memo);
    vector<vector<int>> ksaraju();
    vector<vector<int>> Tarjan()
;    
    
};
