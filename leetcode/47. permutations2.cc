#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void permutations(vector<vector<int>> &result,vector<int> &temp,vector<int> &resource,vector<bool> &memo)
{
    //第二个出点:当临时容器中的元素数量达到resource.size()时
    if(temp.size() == resource.size())
    {
        result.push_back(vector<int>(temp));
        return;
    }

    for(int start = 0; start<resource.size(); start++)
    {
        cout<<"start: "<<start<<" memo : "<<memo[start]<<" value : "<<resource[start]<<" temp size : "<<temp.size()<<endl;
        //额外限制条件应该是，该元素没有被添加过。
        if(memo[start] == true
            || ( start > 0 && resource[start] == resource[start-1] && memo[start-1] == false))
        {
            cout<<"continue"<<endl;
            continue;
        }
        memo[start] = true;
        temp.push_back(resource[start]);
        permutations(result,temp,resource,memo);
        memo[start]=false;
        temp.pop_back();
    }
}

void permutationsPacking(vector<int> &resource)
{
    //需要先排序
    vector<vector<int>> result;
    vector<int> temp;
    vector<bool> memo(resource.size(),false);
    permutations(result,temp,resource,memo);
    for(int i=0;i<result.size();i++)
    {
        cout<<"\n[";
        for(int j =0;j<result[i].size();j++)
        {
            cout<<result[i][j];
            if((j+1)<result[i].size())
            {
                cout<<",";
            }
        }
        cout<<"]\n";
    }
}

int main()
{
    vector<int> i{1,1,3};
    permutationsPacking(i);
}