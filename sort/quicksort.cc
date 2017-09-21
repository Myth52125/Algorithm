#include <algorithm>
#include <vector>
#include <iostream>
#include <stack>
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

size_t partition(size_t start,size_t end,vector<int> &source)
{
    size_t index=start;
    int target=source[end];
    for(int j=start;j<end;j++)
    {
        if(source[j]<target)
        {
            swap(source[j],source[index]);
            index++;
        }
    }
    swap(source[index],source[end]);

    print(source);
    
    return index;
}

void quicksort(size_t start, size_t end,vector<int> &source)
{
    if(start >= end)
    {
        return;
    }
    int p = partition(start,end,source);

    quicksort(start,p-1,source);
    quicksort(p+1,end,source);
}

void quicksortUseStack(size_t start,size_t end,vector<int> &source)
{
    stack<size_t> st;
    if(start<end)
    {
        st.push(start);
        st.push(end);
    }
    size_t s;//start
    size_t e;//end
    size_t p;//partition
    while(!st.empty())
    {
        e=st.top();
        st.pop();
        s=st.top();
        st.pop();

        p=partition(s,e,source);

        if(s<(p-1))
        {
            st.push(s);
            st.push(p-1);
        }
        if((p+1)<e)
        {
            st.push(p+1);
            st.push(e);
        }
    }
}

int main()
{
    vector<int> a{1,2,4,9,6,1,3,5,8,0,3,2,1,7,9,3,8};
    print(a);
    
    quicksortUseStack(0,a.size()-1,a);
    print(a);
}