#include <iostream>
#include <deque>
#include <vector>

using namespace std;
struct Node
{
    Node(int a, int step, int f)
        : a(a), step(step), f(f)
    {
    }
    int a;    //当前1的个数
    int step; //距离权为1的步数
    int f;    //上次1的个数
};

//a:1的个数,b:0的个数，k每次反转的次数。
int turn0to1Counts(int a, int b, int k)
{
    int total = a + b;

    vector<Node> memo(total + 1, Node(-1, -1, -1));
    deque<Node> de;

    //将最后一步放入队列
    Node end{total, 0, -1};
    de.push_back(end);
    //每次可能盛夏的
    int remain1;
    memo[total] = Node(total, 0, -1);
    cout << "de add: " << de.back().a << " " 
        << de.back().step << " " << de.size() << endl;
    
    while (!de.empty())
    {
        Node n = de.front();
        cout << "now : " << n.a << " " << n.step << " " << n.f << endl;
        
        //如果目前正在处理的节点，等于初始状态，表明，已经遍历到了最终结果。
        if (n.a == a)
        {
            return n.step;
        }
        de.pop_front();

        cout << "\n_______" << n.a << " :from_______" << endl;
        
        //判断可能的反转情况：
        //反转1变为0的个数：从0到目前的1正面的数目，依次遍历，但不能超过k
        //因为不能一次反转k+1个1,所以，大于的要略去
        for (int i = 0; i <= n.a && i<=k; i++)
        {
            //原有1的个数+每次能反转的K个数-反转的1个数 应该小于总数
            //这里相当于，两个部分叠加，减去重叠部分的长度，不能超过总长
            if (n.a+k-i<=total)
            {
                remain1 = n.a -i + (k-i);
                //记录已经出现，那么就不要在遍历了。
                if (memo[remain1].a == -1)
                {
                    de.push_back(Node(remain1, n.step + 1, n.a));
                    memo[remain1] = Node(remain1, n.step + 1, n.a);
                    cout << "de add: " << de.back().a << " " 
                        << de.back().step << " " << de.size() << endl;
                }
            }
        }
        cout << "_______" << n.a << "_______\n" << endl;
    }
    //上面没有找到可能的反转
    return -1;
}

int main()
{
    int a, b, k;
    cin >> a >> b >> k;
    cout << "count :" << turn0to1Counts(a, b, k) << endl;
}