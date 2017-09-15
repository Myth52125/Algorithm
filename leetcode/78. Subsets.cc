#include <vector>
#include <iostream>
using namespace std;

void subsets(vector<vector<int>> &result,vector<int> &temp,vector<int> &resource,int tmpStart)
{
    //这里不需要第一个出点，因为不会有k<0的情况啊
    //第二个出点,也没有。最终的出点就是递归到底层，自动返回
    result.push_back(vector<int>(temp));
    
    cout<<"result: "<<result.size()<<" tmpStart: "<<tmpStart<<endl;
    //递归没有到最底层，还能继续深入。
    //如果在for中添加额外的限制添加，那么第一出点就可以不要。    
    //这里还有一个隐含的条件是:依次遍历
    for(int start = tmpStart;start<resource.size();start++)
    {
        //额外限制
        if(resource[start]==resource[start-1])
        {
            continue;
        }
        //将当前处理的节点添加入temp
        temp.push_back(start);
        //这里不一定是k-1。
        subsets(result,temp,resource,tmpStart+1);

        //只要执行到这一句，意味着递归到达最底层，开始返回。
        //需要需要将底层push的元素pop出
        //这里不处理结果是否满足，因为在底层出点的时候已经判断过了。
        //这里的作用就是为了去遍历其他可能。
        //temp.pop_back();
    }
}

void subsetsPacking(vector<int> resource)
{
    //需要判断一下n,k
    vector<vector<int>> result;
    vector<int> temp;
    subsets(result,temp,resource,0);
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
    vector<int> i{1,1,2,3};
    subsetsPacking(i);
}