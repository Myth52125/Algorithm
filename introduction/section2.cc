#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void print_c(const vector<T> &src)
{
    for(T t:src)
    {
        cout<<t<<" ";
    }
}

void print_c_i(const vector<int> &src)
{
    for(size_t i =0;i<src.size();++i)
    {
        cout<<src[i]<<" ";
    }
}

template <typename T>
void func2_1_insertion_sort(vector<T> &src)
{
    size_t len = src.size();
    T wait_add;
    // 默认第一个已经是排好序的，所以从第二个元素开始排序
    for(size_t boundary=1;boundary<len;++boundary)
    {
        // 记录需要排序的元素，应为该位置，可能被其他元素占据
        wait_add = src[boundary];
        // 这里比较需要排序的元素和已排序元素的大小关系
        // 如果待排序的大，那么就待排序的就应该在position的位置
        // 如果待排序的小，那么该元素应该后移一个位置
        for(size_t position=boundary;;--position)
        {
            // for循环的控制条件为空
            // 是因为在if里面控制了，不需要再去控制
            if(position >0 && wait_add<src[position-1])
            {
                src[position]=src[position-1];
            }else{
                src[position]=wait_add;
                break;
            }
        }
    }
}

template <typename T>
void func2_3_1merge_sort_merge(vector<T> &src,size_t start,size_t boundary,size_t end)
{
    // 这里不能初始化大小。不然push_back的时候顺序就乱了
    vector<T> c_tmp;
    // 记录两个小数组的开始位置。
    size_t start2= boundary;
    size_t start1= start;
    // 从两个小数组中选出最小的放进c_tmp
    while(start1 != boundary && start2 != end)
    {
        if(src[start1] > src[start2])
        {
            c_tmp.push_back(src[start2]);
            ++start2;
        }else{
            c_tmp.push_back(src[start1]);
            ++start1;
        }
    }

    // 剩余两个循环，将小数组剩下元素放进c_tmp
    // 下面两个循环只会进一个
    while(start1 != boundary)
    {
        c_tmp.push_back(src[start1]);
        ++start1;
    }
    while(start2 != end)
    {
        c_tmp.push_back(src[start2]);
        ++start2;
    }
    
    // 用排序后的数组替换原数组中的两个元素
    size_t i=0;
    while(start != end)
    {
        src[start]=c_tmp[i];
        ++i;
        ++start;
    }
}

template <typename T>
void func2_3_1merge_sort(vector<T> &src,size_t start,size_t end)
{
    // 这里start+1，主要是为了不会进入死循环，栈越界
    // 比如01的时候
    // start+1 <end,避免了只有一个元素的时候，还继续分
    if(start+1 < end)
    {
        size_t boundary=(start+end)/2;
        func2_3_1merge_sort(src,start,boundary);
        func2_3_1merge_sort(src,boundary,end);
        func2_3_1merge_sort_merge(src,start,boundary,end);
    }
}

int main22()
{
    vector<int> c_i{-1,-71,0,2,3,4,6,8,-9,1,-2,-6,0,9};
    func2_3_1merge_sort(c_i,0,c_i.size());
    print_c_i(c_i);
}