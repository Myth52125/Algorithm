#include <vector>
#include <deque>
#include <stack>
#include <memory>
#include <iostream>
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
    Node(const Node &node)
      :key(node.key),to(node.to),d(node.d),p(node.p),
      reach(node.reach),leave(node.leave),weight(weight)
    {
    }
    Node(int i,int weight)
      :key(i),weight(weight)
    {

    }


    void add(int );
    void add(int ,int);
    

    int key=-1;
    shared_ptr<Node> to=NULL;
    //为广度优先搜索添加的，距离，父节点
    int d=INT32_MAX;
    int p=0;
    //为深度优先搜索记录的发现时间和处理结束时间
    int reach=0;
    int leave=0;
    //父节点到该节点的权重
    int weight=1;
    //为最大流算法添加的已用日嗯亮
    int used=0;
    int usedTo;
};

struct HeapSort
{
    HeapSort(int k,int v)
        :k(k),v(v)
    {
    }
    int k;
    int v;
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
    Graph ksaraju_reverse(vector<Node  > &oldG,vector<Node > &newG);
    void Tarjan_dfs(int n,int &reachTime,vector<int> &reach,vector<int> &low,vector<bool> &flag,stack<int> &st,vector<int> &scc,vector<vector<int>> &result);
    
    void dijkstra_smallheap_build(int start, vector<HeapSort> &heap);
    void dijkstra_smallheap_add(vector<HeapSort> &smallheap, vector<HeapSort> &added);
    HeapSort dijkstra_smallheap_take(vector<HeapSort> &smallheap);
    bool edmonds_dfs(int start, int end, int &pathMin, vector<vector<int>> &passedNode, vector<bool> memo);
    
  public:
    int findBfs(int start, int end);
    int findBfs_re(int start, int end);

    int dfs_re();
    vector<int> dfsTopo();
    vector<int>  kahnTopolgical_sort();
    void dfs(int curKey, int &time ,vector<bool> &memo);
    vector<vector<int>> ksaraju();
    vector<vector<int>> Tarjan();

    void add(vector<int> &);
    void add(vector<vector<int>> &);
    void add(int,int);
    void add(int ,int,int);
    void vertex();
    vector<Node> vList();

    int nonLoopShortest_dfs(int start,int end);
    int dijkstra(int start,int end);
    
    int edmonds(int start, int end);
    
};
