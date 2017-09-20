#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void coin(vector<vector<int>> &result, vector<int> &temp, vector<int> &memo, int max, int remain)
{
    if (remain == 0)
    {
        vector<int> willPush(temp);
        sort(willPush.begin(), willPush.end());
        if (find(result.begin(), result.end(), willPush) == result.end())
        {
            result.push_back(vector<int>(willPush));
        }
        return;
    }

    if (remain < 0)
    {
        return;
    }

    while ((1 << max) < remain)
    {
        max++;
    }

    while ((1 << max) > remain)
    {
        max--;
    }
    cout << "max: " << max << endl;
    while (memo.size() < max + 1)
    {
        memo.push_back(0);
    }

    for (int start = max; start >= 0; start--)
    {
        if (memo[start] > 1)
        {
            continue;
        }

        memo[start]++;
        temp.push_back((1 << start));

        coin(result, temp, memo, max, remain - (1 << start));
        memo[start]--;
        temp.pop_back();
    }
}

void coinPacking(int n)
{
    //需要判断一下n,k
    vector<vector<int>> result;
    vector<int> temp;
    vector<int> memo(0);
    coin(result, temp, memo, 0, n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\n[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if ((j + 1) < result[i].size())
            {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}

int main1()
{
    int remain;
    cin >> remain;
    coinPacking(remain);
}



void coin2(vector<vector<int>> result,vector<int> temp,vector<vector<vector<int>>> memo,long long remain,int old)
{
    if(remain == 0)
    {
        vector<int> pushed(temp);
        sort(pushed.begin(),pushed.end());
        if(find(memo[old].begin(),memo[old].end(),pushed) == memo[old].end())
        {
            memo[old].push_back(pushed);
        }
    }
    return;
    

    for(long long i = 1;i<=remain;i++)
    {
        for(int j = 0 ;j < memo[i].size();i++)
        {
            for(int k = 0;k<memo[i][j].size();i++)
            {
                temp[memo[i][j][k]]++;
                if(temp[memo[i][j][k]] == 2)
                {
                    continue;
                }
            }
            coin2(result,temp,memo,remain - (1<<i),old);
            
        }
    }
}

void coin2Packing(int n)
{
    //需要判断一下n,k
    vector<vector<int>> result;
    vector<int> temp;
    vector<vector<vector<int>>> memo;
    coin2(result, temp, memo, n, n);
    for (int i = 0; i < result.size(); i++)
    {
        cout << "\n[";
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j];
            if ((j + 1) < result[i].size())
            {
                cout << ",";
            }
        }
        cout << "]\n";
    }
}

int main()
{
    int remain;
    cin >> remain;
    coin2Packing(remain);
}
