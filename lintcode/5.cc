#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int findK1(int k,vector<int> &source)
{
    sort(source.begin(),source.end());
    return source[k-1];
}

int findK21(int k,vector<int> &source)
{
    for(size_t i=source.size();i>0;i--)
    {
        for(size_t j = source.size();j>0;j--)
        {
            if(source[i]<source[i-1])
            {
                swap(source[i],source[i-1]);
            }
        }
        k--;
        if(k==0)
        {
            return source[k-1];
        }

    }
}

int findk22(int k,vector<int> &source)
{
    int minIndex;
    for(size_t i = 0; i<source.size();i++)
    {
        minIndex=i;
        size_t j = i;
        for(;j<source.size();j++)
        {
            if(source[minIndex]>source[j])
            {
                minIndex=j;
            }
        }
        swap(source[minIndex],source[j]);
        k--;
        if(k==0)
        {
            return source[k-1];
        }
    }
}


void quicksort(int start,int end,vector<int> &source)
{
    if(start == end)
    {
        return;
    }
    int nextStart = start;
    int nextEnd = end;
    int tmp = start-1;
    cout<<start<<" "<<end<<endl;
    while(start != end)
    {
        if(source[start] < source[end] && tmp >= start)
        {
            swap(source[start],source[tmp]);
            tmp++;
        }
        start++;
    }
    swap(source[end],source[tmp]);
    quicksort(0,tmp,source);
    quicksort(tmp,nextEnd,source);
}



int findk3(int k,vector<int> &source)
{
    
}

int main()
{
    vector<int> a{2,4,6,8,56,3,2,76,8,4,2,3,7,8,9,4,1};
    quicksort(0,a.size(),a);

    for(auto i:a)
    {
        cout<<i<<"";
    }

}