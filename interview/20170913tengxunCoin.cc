#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void permutations(vector<vector<int>> &result,vector<int> &temp,vector<int> &resource)
{
    //第二个出点:当临时容器中的元素数量达到resource.size()时
    if(temp.size()==resource.size())
    {
        result.push_back(vector<int>(temp));
    }

    for(int start = 0;start<resource.size();start++)
    {
        //额外限制条件应该是，该元素没有被添加过。
        if(find(temp.begin(),temp.end(),resource[start]) != temp.end())
        {
            continue;
        }

        temp.push_back(resource[start]);
        permutations(result,temp,resource);
        
        temp.pop_back();
    }
}

void permutationsPacking(vector<int> &resource)
{
    //需要判断一下n,k
    vector<vector<int>> result;
    vector<int> temp;
    permutations(result,temp,resource);
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
    vector<int> i{1,2,3,4,5,6};
    permutationsPacking(i);
}