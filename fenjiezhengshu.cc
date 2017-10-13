#include <iostream>
#include <vector>
#include <unistd.h>
using namespace std;
int fenjie1(int n)
{
    int dp[n+1];

    //初始化为1,表示n拆分为n个1,这一种拆分方法
    for(int i=0;i<=n;i++)
    {
        dp[i]=1;
    }

    int k=2;
    while(k<=n)
    {
        //第一次循环表示，通过将两个1，合并为2，得到的新的方法。
        //因为只有大于2的数才能够使用该拆分方法，所以j初始为2
        //以后拆分方法为4，8，16
        for(int j = k;j<=n;j++)
        {
            //原有的方法个数，加上新的拆分方法个数
            //最精妙
            dp[j]+=dp[j-k];
        }

        k*=2;
    }
    // cout<<dp[n]<<endl;
    return dp[n];
}

void fenjie2_ass(int remain,int k,int &result)
{
    if(remain < 0)
    {
        return;
    }
    if(remain == 0)
    {
        result++;
        return;
    }
    
    while(remain < (1<<k))
    {
        k--;
    }

    for(int i = k;remain>=(1<<i);i--)
    {
        int tmp = remain - (1<<i);
        fenjie2_ass(tmp,i,result);
    }
}

int fenjie2(int n)
{
    int remain=n;
    int k=0;
    while(remain)
    {
        k++;
        remain/=2;
    }
    remain = n;
    int result = 0;
    
    fenjie2_ass(remain,k,result);
    return result;
}

int main()
{
    int n;
    cin>>n;
    cout<<"02: "<<fenjie2(n)<<endl;    
    cout<<"01: "<<fenjie1(n)<<endl;
}