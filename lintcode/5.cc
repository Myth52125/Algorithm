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
    if(k>source.size())
    {
        return INT32_MIN;
    }
    int index = k-1;
    
    sort(source.begin(),source.end());
    return source[index];
}


//冒泡和选择排序
int findK21(int k,vector<int> &source)
{
    if(k>source.size())
    {
        return INT32_MIN;
    }
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
    if(k>source.size())
    {
        return INT32_MIN;
    }
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
    if(k>source.size())
    {
        return INT32_MIN;
    }
    return quicksort(0,source.size()-1,source,k);
}





//堆排序
void heapsort_max(vector<int> &source,int i,int len=0)
{
    int l=i*2;
    int r=i*2+1;
    int maxIndex=i;
    len=len==0?source.size():len;
    if(l<len && source[l]>source[i])
    {   
        maxIndex=l;
    }
    if(r<len && source[r]>source[maxIndex])
    {
        maxIndex=r;
    }
    // cout<<"cur: "<<i<<" max :"<<maxIndex<<" left: "<<source[2*i]<<" right: "<<source[2*i+1]<<endl;
    if(maxIndex != i)
    {
        swap(source[i],source[maxIndex]);
        heapsort_max(source,maxIndex,len);
    }
}

void heapsort_sort(vector<int> &source)
{
    for(int i = source.size()-1;i>1;i--)
    {
        swap(source[1],source[i]);
        heapsort_max(source,1,i);
    
    }
}
void heapsort_build(vector<int> &source)
{
    for(int i = source.size()/2 + 1; i>0 ;i--)
    {
        heapsort_max(source,i);
    }
}

// int heapsort(vector<int> &source)
// {
//     heapsort_build(source);
//     heapsort_sort(source);
// }




int findk5(int k,vector<int> &source)
{
    if(k>source.size())
    {
        return INT32_MIN;
    }
    
    vector<int> tmp;
    tmp.push_back(0);
    
    for(int i=1;i<=k;i++)
    {
        tmp.push_back(source[i-1]);
    }
    heapsort_build(tmp);
    
    for(int i=k;i<source.size();i++)
    {
        if(source[i]<tmp[1])
        {
            tmp[1]=source[i];
            heapsort_build(tmp);
        }
    }
    return tmp[1];
}

int main()
{
    vector<int> a{2,4,6,8,5,3,2,6,8,4,2,3,7,8,9,4,1};
    print(a);
    int k;
    while(cin>>k)
    {

        cout<<findk5(k,a)<<endl;;
        // print(a);
        // cout<<findk22(k,a)<<endl;
    }


    
}