#include "NewGraph.h"
#include <iostream>
#include <algorithm>

template <typename T>
void printMemo(vector<T> memo)
{
    cout << endl;
    for (T i : memo)
    {
        cout << i << " ";
    }
    cout << endl;
}

void printTime(vector<Node> &Vlist)
{
    for (Node i : Vlist)
    {
        cout << "key: " << i.key << " reach: " << i.reach << " leave: " << i.leave << endl;
    }
}

void print2(vector<vector<int>> v)
{
    for (auto i : v)
    {
        cout << endl;
        for (auto j : i)
        {
            cout << j << " ";
        }
    }
}

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
        Node *n1 = new Node(vContainer[curKey]);
        tmp.reset(new Node(vContainer[curKey]));
        // cout<<"share_ptr key: "<<curKey<<" "<<(n1->to->key)<<endl;
        //当前节点有指向别的节点
        while (tmp->to != NULL)
        {
            //当前指向的节点还没有遍历过
            if (memo[tmp->to->key] == false)
            {
                vContainer[tmp->to->key].d = vContainer[tmp->key].d + 1;
                vContainer[tmp->to->key].p = tmp->key + 1;
                tmp->to->p = tmp->key;
                memo[tmp->to->key] = true;
                de.push_back(tmp->to->key);
                cout << " de back: " << de.back() << endl;
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
    cout << curKey << " ";

    //标记为处理结束

    memo[curKey] = true;
    //处理结束，将遍历该节点指向的节点
    shared_ptr<Node> tmp(new Node(vContainer[curKey]));

    //由于是递归，tmp保存在栈中，同一层变量是同一个
    while (tmp->to != NULL)
    {
        if (memo[tmp->to->key] == false)
        {
            vContainer[tmp->to->key].d = vContainer[tmp->to->key].d + 1;
            vContainer[tmp->to->key].p = vContainer[tmp->to->key].key;
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
    vector<bool> memo(vContainer.size() + 1, false);
    //对于有向图，可能存在多个不能到达的点，所以需要依次遍历：
    for (Node i : vContainer)
    {
        if (i.key != -1 && memo[i.key] == false)
        {
            dfs_re_func(i.key, memo);
        }
    }
}

void Graph::dfsTopo_func(int curKey, vector<int> &result, vector<bool> &memo)
{
    memo[curKey] = true;

    shared_ptr<Node> tmp(new Node(vContainer[curKey]));
    while (tmp->to != NULL)
    {

        if (memo[tmp->to->key] == false)
        {
            // cout<<"curKey: "<<curKey<<endl;

            dfsTopo_func(tmp->to->key, result, memo);
            //当该递归返回时，表示该节点处理完了，
            //并且该节点所有的自己点，以及指向的子节点也都处理完了
            // cout<<"push: "<<tmp->to->key<<endl;

            result.push_back(tmp->to->key);
        }
        tmp = tmp->to;
    }
}

vector<int> Graph::dfsTopo()
{
    vector<int> result;
    vector<bool> memo(vContainer.size() + 1, false);

    for (Node i : vContainer)
    {
        // cout<<"i.key: "<<i.key<<endl;
        if (i.key != -1 && memo[i.key] == false)
        {
            dfsTopo_func(i.key, result, memo);
            result.push_back(i.key);
        }
    }
    reverse(result.begin(), result.end());
    printMemo(result);
    return result;
}

vector<int> Graph::kahnTopolgical_sort()
{
    vector<int> result;                             //存放最终结果
    deque<int> de;                                  //存放入度为0的节点
    vector<int> indegree(vContainer.size() + 1, 0); //存放节点的入度

    //计算所有节点的入度
    shared_ptr<Node> tmp;
    for (Node i : vContainer)
    {
        if (i.key != -1)
        {
            tmp = make_shared<Node>(Node(i));
            while (tmp->to != NULL)
            {
                indegree[tmp->to->key]++;
                tmp = tmp->to;
            }
        }
    }

    //将入度为0的节点放入de中
    for (int i = 0; i < indegree.size(); i++)
    {
        if (vContainer[i].key != -1)
        {
            if (0 == indegree[i])
            {
                de.push_back(i);
            }
        }
    }
    cout << "indegree: " << indegree.size() << "  " << vContainer.size() + 1;
    printMemo(indegree);

    int curKey;
    shared_ptr<Node> curNode;

    //每次从de中取元素，然后遍历其指向的元素
    //并将指向节点的入度--，如果为0,也放入de。
    while (!de.empty())
    {
        curKey = de.front();
        de.pop_front();
        result.push_back(curKey);
        curNode = make_shared<Node>(Node(vContainer[curKey]));
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
    cout << "result: ";
    printMemo(result);
}

void Graph::dfs(int curKey, int &time, vector<bool> &memo)
{

    memo[curKey] = true;
    shared_ptr<Node> tmp(new Node(vContainer[curKey]));
    vContainer[tmp->key].reach = ++time;
    while (tmp->to != NULL)
    {
        tmp = tmp->to;
        if (memo[tmp->key] == false)
        {
            dfs(tmp->key, time, memo);
        }
    }
    vContainer[curKey].leave = ++time;
}

void Graph::ksaraju_dfs(int curKey, vector<bool> &memo, vector<int> &scc, vector<Node> &vContainer)
{
    memo[curKey] = true;

    shared_ptr<Node> tmp(new Node(vContainer[curKey]));
    scc.push_back(curKey);

    while (tmp->to != NULL)
    {
        tmp = tmp->to;
        curKey = tmp->key;
        if (memo[curKey] == false)
        {
            ksaraju_dfs(curKey, memo, scc, vContainer);
        }
    }
}

void Graph::ksaraju_calOrder(vector<Node> &vContainer, vector<int> &order)
{
    int total = (vContainer.size() - 1) * 2;
    for (int i = total; i > 0; i--)
    {
        for (Node node : vContainer)
        {
            if (node.leave == i)
            {
                order.push_back(node.key);
                break;
            }
        }
    }
}
Graph Graph::ksaraju_reverse(vector<Node> &oldG, vector<Node> &newG)
{
    Graph g;
    for (Node i : oldG)
    {
        if (i.key != -1)
        {
            shared_ptr<Node> tmp(new Node(i));
            while (tmp->to != NULL)
            {
                tmp = tmp->to;
                g.add(tmp->key, i.key);
            }
        }
    }
    newG = g.vList();
    g.vertex();
    return g;
}

vector<vector<int>> Graph::ksaraju()
{

    //深度优先搜索。
    int time = 0;
    vector<bool> memo(vContainer.size() + 1, false);
    for (Node i : vContainer)
    {
        if (i.key != -1)
        {
            if (memo[i.key] == false)
            {
                dfs(i.key, time, memo);
            }
        }
    }
    cout << "print time" << endl;
    printTime(vContainer);

    //获取反向图遍历节点的顺序
    vector<int> order;
    ksaraju_calOrder(vContainer, order);

    cout << "older :";
    printMemo(order);
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
    cout << "ksaraju: ";
    print2(result);
    return result;
}

//Tarjan_dfs的深度优先搜索
void Graph::Tarjan_dfs(int curKey, int &reachTime, vector<int> &reach,
                       vector<int> &low, vector<bool> &flag, stack<int> &st, vector<int> &scc, vector<vector<int>> &result)
{
    int childKey;
    //设置正在处理节点的reach和low
    low[curKey] = reach[curKey] = reachTime++;

    flag[curKey] = true;
    //压入栈
    st.push(curKey);
    //处理其子节点
    cout << "cur:child: " << curKey << " " << reach[curKey] << " " << low[curKey] << endl;

    shared_ptr<Node> curNode(new Node(vContainer[curKey]));

    while (curNode->to != NULL)
    {
        childKey = curNode->to->key;
        //如果该节点已经处理过了
        if (reach[childKey] != 0 && flag[childKey])
        {
            low[curKey] = reach[childKey];

            //  cout<<"cur : reach :"<<curKey<<" "
            //     <<reach[curKey]<<" "<<low[curKey]<<endl;
        }
        else if (reach[childKey] == 0)
        {
            cout << "child: " << childKey << " " << (flag[childKey]) << " " << reach[childKey] << endl;

            //处理还没被处理的节点
            Tarjan_dfs(childKey, reachTime, reach, low, flag, st, scc, result);
            //递归返回的时候判断，low是否等于reach
            if (low[childKey] < low[curKey])
            {
                low[curKey] = low[childKey];
            }
        }
        curNode = curNode->to;
    }

    int tmp;
    if (low[curKey] == reach[curKey])
    {
        do
        {
            tmp = st.top();
            st.pop();
            scc.push_back(tmp);
            flag[curKey] = false;
        } while (curKey != tmp);

        result.push_back(scc);
        scc.erase(scc.begin(), scc.end());
    }
}

vector<vector<int>> Graph::Tarjan()
{
    int len = vContainer.size();
    vector<int> reach(len, 0);
    vector<int> low(len, 0);
    vector<bool> flag(len, false);
    stack<int> st;
    vector<int> scc;
    vector<vector<int>> result;
    int reachTime = 1;
    for (Node n : vContainer)
    {
        if (n.key != -1 && reach[n.key] == 0)
        {
            Tarjan_dfs(n.key, reachTime, reach, low, flag, st, scc, result);
        }
    }

    for (Node n : vContainer)
    {
        if (n.key != -1)
        {
            cout << "key: " << n.key << " reach: " << reach[n.key]
                 << " low: " << low[n.key] << endl;
        }
    }

    cout << "Tarjan: ";
    print2(result);
    return result;
}

void Graph::add(vector<int> &v)
{
    if(v.size()==2)
    {
        add(v[0], v[1]);
    }else if(v.size()==3){
        add(v[0],v[1],v[2]);
    }
}


void Graph::add(vector<vector<int>> &vs)
{
    for (auto i : vs)
    {
        add(i);
    }
}
void Graph::add(int v1, int v2)
{
    if (vContainer.size() < v1 + 1 || vContainer.size() < v2 + 1)
    {
        vContainer.resize(max(v1, v2) + 1);
    }

    vContainer[v1].key = v1;
    vContainer[v2].key = v2;

    vContainer[v1].add(v2);
}
void Graph::add(int v1,int v2,int weight)
{
    if (vContainer.size() < v1 + 1 || vContainer.size() < v2 + 1)
    {
        vContainer.resize(max(v1, v2) + 1);
    }

    vContainer[v1].key = v1;
    vContainer[v2].key = v2;

    vContainer[v1].add(v2,weight);
}
void Node::add(int next,int weight)
{
    shared_ptr<Node> *tmp = &to;
    if ((*tmp) != NULL)
    {
        while ((*tmp)->to != NULL)
        {
            *tmp = (*tmp)->to;
        }
        (*tmp)->to.reset(new Node(next,weight));
    }
    else
    {
        (*tmp).reset(new Node(next,weight));
    }
}

void Node::add(int next)
{
    // cout<<"Node::add : "<<next<<endl;
    // printNode(this);

    shared_ptr<Node> *tmp = &to;
    // printNode(to);

    // cout<<"Node::add to: "<<(to==NULL)<<endl;
    if ((*tmp) != NULL)
    {
        while ((*tmp)->to != NULL)
        {
            // cout<<"tmp key: "<<(*tmp)->key<<" to: "<<(*tmp)<<endl;
            *tmp = (*tmp)->to;
        }
        (*tmp)->to.reset(new Node(next));
    }
    else
    {
        (*tmp).reset(new Node(next));
    }

    // printNode(this);

    // tmp=make_shared<Node>(Node(next));
    // cout<<"Node::add : "<<to->key<<endl;
}

void Graph::vertex()
{
    cout << "all vertex: " << endl;
    for (Node i : vContainer)
    {
        if (i.key != -1)
        {
            cout << "node " << i.key << " : ";
            shared_ptr<Node> tmp = i.to;
            while (tmp != NULL)
            {
                cout << tmp->key << " ";
                tmp = tmp->to;
            }
            cout << endl;
        }
    }
}

vector<Node> Graph::vList()
{
    return vContainer;
}

int Graph::nonLoopShortest_dfs(int start, int end)
{
    deque<int> de;
    de.push_back(start);
    vContainer[start].d = 0;
    vContainer[start].p = 0;

    shared_ptr<Node> childNode;
    shared_ptr<Node> curNode;
    int curKey;
    int childKey;
    int tmpDis;

    //可以先计算入度，然后在每次遍历到end节点的时候入度--。为0的时候可以返回。

    int endIndegree;
    while (!de.empty())
    {
        curKey = de.front();
        de.pop_front();
        //
        //这里可以处理endIndegree
        //

        curNode.reset(new Node(vContainer[curKey]));
        while (curNode->to != NULL)
        {
            childKey = curNode->to->key;
            tmpDis = vContainer[start].d + vContainer[childKey].weight;
            //如果该条路径到达子节点的路径短，那么需要松弛操作，同时重新计算子节点后面的节点。
            if (vContainer[childKey].d > tmpDis)
            {
                vContainer[childKey].d = tmpDis;
                vContainer[childKey].p = start;
                de.push_back(childKey);
            }
            curNode = curNode->to;
        }
    }
    //最后才能返回d的值。因为无法判断有机条路径能够到达d;
    return vContainer[end].d;
}



//建堆用的递归函数
void Graph::dijkstra_smallheap_build(int start, vector<HeapSort> &heap)
{
    int l = start * 2;
    int r = start * 2 + 1;
    int index = start;
    if (l < heap.size() && heap[index].k > heap[l].k)
    {
        index = l;
    }
    if (r < heap.size() && heap[index].k > heap[r].k)
    {
        index = r;
    }
    if (index != start)
    {
        swap(heap[start], heap[index]);
        dijkstra_smallheap_build(index, heap);
    }
}

//想堆中添加元素
void Graph::dijkstra_smallheap_add(vector<HeapSort> &smallheap, vector<HeapSort> &added)
{
    smallheap.insert(smallheap.end(),added.begin(),added.end());

    for(int i=smallheap.size()/2+1;i>0;i--)
    {
        dijkstra_smallheap_build(i,smallheap);
    }

}
//取出堆顶元素
HeapSort Graph::dijkstra_smallheap_take(vector<HeapSort> &smallheap)
{

    HeapSort ret= smallheap[1];
    smallheap[1]=smallheap.back();
    smallheap.pop_back();
    dijkstra_smallheap_build(1,smallheap);
    return ret;
}

//主要算法
int Graph::dijkstra(int start,int end)
{
    vector<HeapSort> smallheap;
    vector<HeapSort> added;

    HeapSort tmp(0,start);
    added.push_back(tmp);
    dijkstra_smallheap_add(smallheap,added);

    shared_ptr<Node> curNode;
    int tmpDis;
    while(!smallheap.empty())
    {
        HeapSort cur=dijkstra_smallheap_take(smallheap);
        
        curNode = make_shared<Node>(Node(vContainer[cur.v]));
        added.erase(added.begin(),added.end());
        while(curNode->to != NULL)
        {
            tmpDis = vContainer[cur.v].d+curNode->to->weight;
            if(tmpDis <  vContainer[curNode->to->key].d)
            {
                vContainer[curNode->to->key].d=tmpDis;
                added.push_back(HeapSort(tmpDis,curNode->to->key));
            }
            curNode=curNode->to;
        }
        dijkstra_smallheap_add(smallheap,added);
    }

    return vContainer[end].d;
}


