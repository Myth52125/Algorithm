#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

size_t  fishCounts(int maxSize,int minSize,int count,vector<int> &fishs)
{
    //计算范围
    vector<vector<int>> memo(count+1,{0,0,0,0});
    for(int i = 1;i<count+1;i++)
    {
        memo[i][0]=fishs[i]*2;
        memo[i][1]=fishs[i]*10;
        memo[i][2]=fishs[i]/2;
        //这里ceil()的原因在与，向下取整。比如105/10.0=10.5
        memo[i][3]=static_cast<int>(ceil(fishs[i]/10.0));       
    }

    //暴力枚举
    vector<bool> counts(maxSize-minSize+1,true);
    for(int i = minSize;i<=maxSize;i++)
    {
        for(int j=1;j<count+1 && counts[maxSize-i];j++)
        {
            if( counts[maxSize-i] && (i>=memo[j][0] && i<=memo[j][1]) || (i>=memo[j][2] && i<=memo[j][3]))
            {
                counts[maxSize-i]=false;
            }
        }
    }

    int ret=0;
    for(auto i:counts)
    {
        if(i)
        {
            ret++;
        }
    }
    return ret;
}



int main()
{
    int maxSize,minSize,count;
    cin>>minSize>>maxSize>>count;
    vector<int> fishs(count+1);
    for(int i = 1;i<=count;i++)
    {
        cin>>fishs[i];
    }
    cout<<"size : "<<fishCounts(maxSize,minSize,count,fishs)<<endl;
}