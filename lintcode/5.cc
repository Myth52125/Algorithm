#include <iostream>
#include <algorithm>
#include <vector>
#include <unistd.h>
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

int quicksortPartition(int start,int end,vector<int> &source)
{
    int x = source[end];
    int i = start;
    for(int j=start;j<end;j++)
    {
        if(source[j]<x)
        {
            swap(source[i],source[j]);
            i++;
        }
    }
    swap(source[i],source[end]);
    return i;
}
void quicksort(int start,int end,vector<int> &source)
{
    if(start >= end)
    {
        return;
    }
    int i=quicksortPartition(start,end,source);

    cout<<endl;
    for(auto i:source)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    sleep(1);
    quicksort(start,i-1,source);

    quicksort(i+1,end,source);
}



int findk3(int k,vector<int> &source)
{
    
}

int main()
{
    vector<int> a{2,4,6,8,5,3,2,6,8,4,2,3,7,8,9,4,1};
    quicksort(0,a.size()-1,a);

    cout<<endl;
    for(auto i:a)
    {
        cout<<i<<"";
    }
    cout<<endl;
    
}