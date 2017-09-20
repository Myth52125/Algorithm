#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

int64_t uglyNum(int64_t n)
{
    deque<int64_t> two;
    deque<int64_t> three;
    deque<int64_t> five;
    two.push_back(1);
    
    int64_t i = 0;
    int64_t tmp;
    INT
    int64_t twoMin;
    int64_t threeMin;
    int64_t fiveMin;
    
    int64_t ret;
    while(i != n)
    {
        i++;
        twoMin = two.empty()?INT64_T:two.front();
        threeMin = three.empty()?INT64_T:three.front();
        fiveMin = five.empty()?INT64_T:five.front();
        tmp =  min(min(twoMin,threeMin),fiveMin);
        
        if(tmp==twoMin)
        {
            ret=twoMin;
            two.push_back(2*ret);
            three.push_back(3*ret);
            five.push_back(5*ret);
            two.pop_front();
            continue;
        }
        if(tmp == threeMin)
        {
            ret=three.front();
            three.push_back(3*ret);
            
            five.push_back(5*ret);
            three.pop_front();
            
            continue;
        }
        if(tmp == fiveMin)
        {
            ret=five.front();
            five.push_back(5*ret);
            five.pop_front();
            continue;            
        }

    }
    return ret;
   
}




int64_t main()
{
    int64_t i;
    while(cin>>i)
    {
        cout<<"ugly :"<<uglyNum(i)<<endl;
    }
}