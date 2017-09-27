#include "NewGraph.h"
#include <iostream>
#include <algorithm>
int Graph::findBfs(int start, int end)
{
    deque<int> de;
    //用来记录节点是否被遍历过。
    vector<bool> memo(vContainer.size(), false);
    //先将其实节点push进去
    //其实点距离自己的距离为0,父节点设为自己吧。
    vContainer[start].d = 0;
    vContainer[start].p = start;

    de.push_back(start);
    memo[start] = true;
    int curKey;
    shared_ptr<Node> tmp;
    while (!de.empty())
    {
        curKey = de.front();
        //处理cur：可是是比较是否等于终点，可能是其他,
        //这里处理两点之间的最短距离

        if (curKey == end)
        {
            return vContainer[curKey].d;
        }

        //处理结束，将该节点弹出。
        de.pop_front();

        //节点处理完毕以后，将节点指向的节点以此添加到队列中
        tmp = make_shared<Node>(new Node(vContainer[curKey]));
        //当前节点有指向别的节点
        while (tmp->to != NULL)
        {
            //当前指向的节点还没有遍历过
            if (memo[tmp->to->key] == false)
            {
                tmp->to->d = tmp->d + 1;
                tmp->to->p = tmp->key;
                memo[tmp->to->key] = true;
                de.push_back(tmp->to->key);
            }
            //指向当前节点，指向的下一个节点
            tmp = tmp->to;
        }
    }
    //能够达到这里说明每个节点都遍历过了，
    //以为这两点之间不联通，可能是有向图，或者不是一个连通图
    return -1;
}

void Graph::dfs_re_func(int curKey, vector<bool> &memo)
{
    //如果想要尽早尽快结束遍历，需要额外的变量：引用或者指针
    //这里使用：finded
    //处理该节点,同时设置结束表示
    cout << curKey << endl;

    //标记为处理结束
    memo[curKey] = true;

    //处理结束，将遍历该节点指向的节点
    shared_ptr<Node> tmp(new Node(vContainer[curKey]));

    //由于是递归，tmp保存在栈中，同一层变量是同一个
    while (tmp->to != NULL)
    {
        if (memo[tmp->to->key] == false)
        {
            tmp->to->d = tmp->d + 1;
            tmp->to->p = tmp->key;
            dfs_re_func(tmp->to->key, memo);
            //节点返回代表该极点的子节点都处理完毕了。

            //如果希望尽快结束遍历，需要额外的变量：引用或者指针
            //这里检查结束标志return
        }
        //去遍历同层的下一个
        tmp = tmp->to;
    }
}

int Graph::dfs_re()
{
    vector<bool> memo;
    //对于有向图，可能存在多个不能到达的点，所以需要依次遍历：
    for (Node i : vContainer)
    {
        dfs_re_func(i.key, memo);
    }
}

void Graph::dfsTopo_func(int curKey, vector<int> &result, vector<bool> &memo)
{

    memo[curKey] = true;
    shared_ptr<Node> tmp(new Node(vContainer[curKey]));
    while (tmp->to != NULL)
    {
        curKey = tmp->to->key;
        if (memo[curKey] == false)
        {
            dfsTopo_func(curKey, result, memo);
            //当该递归返回时，表示该节点处理完了，
            //并且该节点所有的自己点，以及指向的子节点也都处理完了
            result.push_back(curKey);
        }
        tmp = tmp->to;
    }
}

vector<int> Graph::dfsTopo()
{
    vector<int> result;
    vector<bool> memo;

    for (Node i : vContainer)
    {
        dfsTopo_func(i.key, result, memo);
    }
    reverse(result.begin(), result.end());
    return result;
}

void Graph::kahnTopolgical_sort()
{
    vector<int> result;                         //存放最终结果
    deque<int> de;                              //存放入度为0的节点
    vector<int> indegree(vContainer.size(), 0); //存放节点的入度

    //计算所有节点的入度
    shared_ptr<Node> tmp;
    for (Node i : vContainer)
    {
        tmp = make_shared<Node>(new Node(i));
        while (tmp->to != NULL)
        {
            indegree[tmp->to->key]++;
            tmp = tmp->to;
        }
    }
    //将入度为0的节点放入de中
    for (int i = 0; i < indegree.size(); i++)
    {
        if (0 == indegree[i])
        {
            de.push_back(i);
        }
    }

    int curKey;
    shared_ptr<Node> curNode;
    //每次从de中取元素，然后遍历其指向的元素
    //并将指向节点的入度--，如果为0,也放入de。
    while (!de.empty())
    {
        curKey = de.front();
        de.pop_front();
        curNode = make_shared<Node>(new Node(vContainer[curKey]));
        while (curNode->to != NULL)
        {
            curNode = curNode->to;
            curKey = curNode->key;
            indegree[curKey]--;
            if (0 == indegree[curKey])
            {
                de.push_back(curKey);
            }
        }
    }
}

void Graph::dfs(int curKey, int &time, vector<bool> &memo)
{

    memo[curKey] = true;
    shared_ptr<Node> tmp = make_shared<Node>(new Node(vContainer[curKey]));
    while (tmp->to != NULL)
    {
        tmp = tmp->to;
        curKey = tmp->key;
        if (memo[curKey] == false)
        {
            tmp->reach = ++time;
            dfs(curKey, time, memo);
            tmp->leave = ++time;
        }
        tmp = tmp->to;
    }
}

void Graph::ksaraju_dfs(int curKey, vector<bool> &memo, vector<int> &scc, vector<Node> &vContainer)
{
    memo[curKey] = true;
    shared_ptr<Node> tmp(new Node(vContainer[curKey]));
    while (tmp->to != NULL)
    {
        tmp = tmp->to;
        curKey = tmp->key;
        if (memo[curKey] == false)
        {
            scc.push_back(curKey);
            ksaraju_dfs(curKey, memo, scc, vContainer);
        }
        tmp = tmp->to;
    }
}

void Graph::ksaraju_calOrder(vector<Node> &vContainer, vector<int> &order)
{
    int total = (vContainer.size() + 1) * 2;
    for (int i = total; total > 0; i--)
    {
        for (Node node : vContainer)
        {
            if (node.leave == total)
            {
                order.push_back(node.key);
                continue;
            }
        }
    }
}
void Graph::ksaraju_reverse(vector<Node> &oldG, vector<Node> &newG)
{
    //...
}

vector<vector<int>> Graph::ksaraju()
{

    //深度优先搜索。
    int time = 0;
    vector<bool> memo(vContainer.size(), false);
    for (Node i : vContainer)
    {
        if (memo[i.key] == false)
        {
            dfs(i.key, time, memo);
        }
    }

    //获取反向图遍历节点的顺序
    vector<int> order;
    ksaraju_calOrder(vContainer, order);

    //构造反向图
    vector<Node> reverseGraph;
    ksaraju_reverse(vContainer, reverseGraph);

    //根据正线图遍历离开节点时间，从大到小的顺序遍历
    vector<vector<int>> result;
    memo = vector<bool>(reverseGraph.size(), false);
    for (int curKey : order)
    {
        if (memo[curKey] == false)
        {
            vector<int> scc;
            ksaraju_dfs(curKey, memo, scc, reverseGraph);
            //这里添加的是副本
            result.push_back(scc);
        }
    }
    return result;
}

//Tarjan_dfs的深度优先搜索
void Graph::Tarjan_dfs(int curKey, int &reachTime, vector<int> &reach, vector<int> &low, vector<bool> &flag, stack<int> &st)
{
    int childKey;
    //设置正在处理节点的reach和low
    reach[curKey] = reachTime++;
    low[curKey] = reachTime++;
    flag[childKey] = true;
    //压入栈
    st.push(curKey);
    //处理其子节点
    shared_ptr<Node> curNode(new Node(vContainer[curKey]));
    while (curNode->to != NULL)
    {
        childKey = curNode->to->key;
        //如果该节点已经处理过了
        if (reach[childKey] != 0)
        {
            low[curKey] == reach[childKey];
        }
        else
        {
            //处理还没被处理的节点
            Tarjan_dfs(curNode->to->key, reachTime, reach, low, flag, st);
            //递归返回的时候判断，low是否等于reach
            if (low[childKey] < low[curKey])
            {
                low[curKey] = low[childKey];
            }
        }
        curNode = curNode->to;
    }
}

vector<vector<int>> Graph::Tarjan()
{
    int len = vContainer.size();
    vector<int> reach(len, 0);
    vector<int> low(len, 0);
    vector<bool> flag(len, false);
    stack<int> st;
    int reachTime = 1;
    for (Node n : vContainer)
    {
        Tarjan_dfs(n.key, reachTime, reach, low, flag, st);
    }

    int curKey;
    vector<int> tmp;
    vector<vector<int>> result;
    do
    {
        curKey = st.top();
        st.pop();

        tmp.push_back(curKey);
        if (low[curKey] = reach[curKey])
        {
            result.push_back(tmp);
            tmp.erase(tmp.begin(), tmp.end());
        }
    } while (!st.empty());
    return result;
}

void Graph::add(vector<int> &v)
{
    vContainer.resize(v[0]+1);

    cout<<"vContainer size(): "<<vContainer.size()<<" "<<v[0]<<endl;
    if (vContainer[v[0]].key == -1)
    {
        Node n(v[0]);
        vContainer[v[0]] = n;
    }
    vContainer[v[0]].add(v[1]);
}

void Graph::add(vector<vector<int>> &vs)
{
    for(auto i:vs)
    {
        add(i);
    }
}

void Node::add(int next)
{
    shared_ptr<Node> tmp = to;
    while (tmp != NULL)
    {
        tmp = tmp->to;
    }
    tmp= make_shared<Node>(new Node(next));
}
