#include <iostream>
#include <algorithm>
#include <vector>
#include <unistd.h>
using namespace std;

void print(vector<int> &source)
{
    cout<<endl;
    for(auto i:source)
    {
        cout<<i<<" ";
    }
    cout<<endl;
}

//先排序，后查找
int findK1(int k,vector<int> &source)
{
    int index = k-1;
    
    sort(source.begin(),source.end());
    return source[index];
}


//冒泡和选择排序
int findK21(int k,vector<int> &source)
{
    int index = k-1;
    for(size_t i=0;i<source.size();i++)
    {
        for(size_t j = source.size()-1;j>i;j--)
        {
            if(source[j]<source[j-1])
            {
                swap(source[j],source[j-1]);
            }
        }
        print(source);
        
        if(i == index)
        {
            return source[index];
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
            cout<<"now :"<<source[j]<<" "<<source[j-1]<<" minIndex: "<<minIndex<<endl;
            
        }
        swap(source[minIndex],source[i]);
        print(source);
        if((k-1) == i)
        {
            return source[k-1];
        }
    }
}




//快排思想实现

int quicksortPartition(int start,int end,vector<int> &source)
{
    int x = source[end];
    int i = start-1;
    for(int j=start;j<end;j++)
    {
        if(source[j]<x)
        {
            i++;
            swap(source[i],source[j]);
        }
    }
    i++;
    swap(source[i],source[end]);

    cout<<endl;
    for(auto i:source)
    {
        cout<<i<<" ";
    }
    cout<<endl;

    return i;
}

int quicksort(int start,int end,vector<int> &source ,int k)
{
    if(start >= end)
    {
        return -1;
    }
    int i=quicksortPartition(start,end,source);
    if(i>k && i-1 != start)
    {
        quicksort(start,i-1,source,k);
    }else if((i)<k && i+1 != end){
        quicksort(i+1,end,source,k);
    }else{
        return source[i];
    }

}



int findk3(int k,vector<int> &source)
{
    return quicksort(0,source.size()-1,source,k);
}


int findk4(int k,vector<int> &source)
{
    int index = k-1;

}



//堆排序
void heapsort_max(vector<int> &source,int i)
{
    int l=i*2;
    int r=i*2+1;
    int maxIndex=i;
    if(l<=source.size() && source[l]>source[i])
    {   
        maxIndex=l;
    }
    if(r<source.size() && source[r]>source[maxIndex])
    {
        maxIndex=r;
    }

    if(maxIndex != i)
    {
        swap(source[i],source[maxIndex]);
        heapsort_max(source,maxIndex);
    }
}

void heapsort_build(vector<int> &source)
{
    for(size_t i = source.size()/2 + 1;i>=0;i--)
    {
        heapsort_max(source,i);
    }
}

int heapsort(vector<int> &source, int max)
{

}




int findk4(int k,vector<int> &source)
{

}

int main()
{
    vector<int> a{2,4,6,8,5,3,2,6,8,4,2,3,7,8,9,4,1};
    int k;
    while(cin>>k)
    {

        heapsort_build(source);
        // cout<<findk22(k,a)<<endl;
    }


    
}