#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string commonStr(string &l,string &r)
{
    int llen=l.size();
    int rlen=r.size();
    //memo[i][j]中存储的是:第一个字符串长i,第二个长j时
    //最长公共子字符串。
    vector<vector<int>> memo(llen+1,vector<int>(rlen+1,0));
    vector<vector<int>> memoPath(llen+1,vector<int>(rlen,0));
    
    memo[0][0]=0;
    
    for(int li = 1;li<=llen;li++)
    {
        for(int ri = 1;ri<=rlen;ri++)
        {
            //当某个字符相等时，标记字符串长度比之前的+1;
            if(l[li-1]==r[ri-1])
            {
                memo[li][ri]=memo[li-1][ri-1]+1;
                memoPath[li][ri]=1;
            //当不同时，选取，能够达到ij长度的两条子字符串的最长长度
            //(i-1)j和i(j-1)这两条字符串能够到达ij
            }else if(memo[li][ri-1]>memo[li-1][ri]){
                memo[li][ri]=memo[li][ri-1];
                memoPath[li][ri]=2;
            }else{
                memo[li][ri]=memo[li-1][ri];
                memoPath[li][ri]=3;
            }
        }
    }       


    for(auto i:memo)
    {
        cout<<endl;
        for(auto j:i)
        {
            cout<<j<<" ";
        }
    }
      

    cout<<endl;


    
    int pathL=memoPath.size()-1;
    int pathR=memoPath[0].size()-1;
    string s;
    while(pathL>0 && pathR>0)
    {
        if(memoPath[pathL][pathR] == 1)
        {
            s.push_back(l[pathL-1]);
            pathL--;
            pathR--;
        }else if(memoPath[pathL][pathR] == 2)
        {
            pathR--;
        }else{
            pathL--;
        }
    }
    reverse(s.begin(),s.end());

    cout<<endl;
    return s;
    
    
}








int main()
{
    string l,r;
    // cin>>l>>r;
    l="bdcaba";
    r="abcbdab";
    cout<<"result: "<<commonStr(l,r)<<endl;
}