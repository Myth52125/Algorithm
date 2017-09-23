#include <iostream>
#include <deque>
#include <vector>

using namespace std;
struct Node
{
    Node(int a,int step,int f)
        :a(a),step(step),f(f)
        {

        }
    int a;//当前1的个数
    int step;//距离权为1的步数
    int f;//上次1的个数
};

//a:1的个数,b:0的个数，k每次反转的次数。
int turn0to1Counts(int a,int b,int k)
{
    int total=a+b;
    
    vector<Node> memo(total+1,Node(-1,-1,-1));
    deque<Node> de;
    Node end{total,0,-1};
    de.push_back(end);
    while(!de.empty())
    {
        Node n = de.front();
        if(n.a == a)
        {
            cout<<"now : "<<n.a<<" "<<n.step<<" "<<n.f<<endl;
            return n.step;
        }
        de.pop_front();
        
        // if(memo[n.a].step>n.a)
        // {
        //     swap(memo[n.a],n);
        // }

        //k反转1变为0的个数
        for(int i = 0;i<=k;i++)
        {
            int remain1=n.a-k<0?-(n.a-k):n.a-k;

            if(memo[remain1].a == -1)
            {
                de.push_back(Node(remain1,n.step+1,n.f));
                memo[remain1]=Node(remain1,n.step+1,n.f);
                cout<<"de back 1 : "<<de.back().a<<" "<<de.back().step<<" "<<de.size()<<endl;
            
            }
            
        }
    }
    
}

int main()
{
    int a,b,k;
    cin>>a>>b>>k;
    cout<<" count :"<<turn0to1Counts(a,b,k)<<endl;
}