#include <vector>
#include <deque>
#include <stack>
#include <memory>
using namespace std;

struct Node
{
    Node()
      :key(-1)
    {
    }
    Node(int i)
      :key(i)
    {
      
    }
    void add(int );


    int key;
    shared_ptr<Node> to;
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
    Graph()
    {

    }

  private:
    vector<Node> vContainer;

    void dfs_re_func(int curKey, vector<bool> &memo);
    void dfsTopo_func(int curKey, vector<int> &result ,vector<bool> &memo );
    void ksaraju_dfs(int curKey,vector<bool> &memo,vector<int> &scc,vector<Node  >& vContainer);    
    void ksaraju_calOrder(vector<Node > &vContainer,vector<int> &order);
    void ksaraju_reverse(vector<Node  > &oldG,vector<Node > &newG);
    void Tarjan_dfs(int n,int &reachTime,vector<int> &reach,vector<int> &low,vector<bool> &flag,stack<int> &st);
    
  public:
    int findBfs(int start, int end);
    int findBfs_re(int start, int end);

    int dfs_re();
    vector<int> dfsTopo();
    void kahnTopolgical_sort();
    void dfs(int curKey, int &time ,vector<bool> &memo);
    vector<vector<int>> ksaraju();
    vector<vector<int>> Tarjan();

    void add(vector<int> &);
    void add(vector<vector<int>> &);
    
    
};
