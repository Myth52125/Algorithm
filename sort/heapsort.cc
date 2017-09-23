#include <vector>
#include <algorithm>
#include <iostream>


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
        print(source);
    
    }
}
void heapsort_build(vector<int> &source)
{
    for(int i = source.size()/2 + 1; i>0 ;i--)
    {
        heapsort_max(source,i);
    }
    heapsort_sort(source);
}