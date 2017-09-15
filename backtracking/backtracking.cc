void backtracking(vector<vector<int>> &result,vector<int> &temp,int tmpStartb)
{
    //当递归到了最低层，需要返回的两个出点
    //第一个出点(可以没有)：该出点表示当前容器的结果不满足要求。直接返回
    if()
    {
        return;
    }
    //第二个出点(一般都有)：该出点表示当前结果满足要求，所以将目前临时容器的副本存入最终结果容器
    if()
    {
        result.push_back(vector<int>(temp));
    }

    //递归没有到最底层，还能继续深入。
    //如果在for中添加额外的限制添加，那么第一出点就可以不要。    
    //这里还有一个隐含的条件是:依次遍历
    for()
    {
        //添加额外的限制条件
        if(int start = tmpStart;...)
        {
            //使用continue跳过
            continue;
        }

        //将当前处理的节点添加入temp
        temp.push_back(...);
        //这里不一定是k-1。
        backtracking(result,temp,start+1);

        //只要执行到这一句，意味着递归到达最底层，开始返回。
        //需要需要将底层push的元素pop出
        //这里不处理结果是否满足，因为在底层出点的时候已经判断过了。
        //这里的作用就是为了去遍历其他可能。
        temp.pop_back();
    }
}