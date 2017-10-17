//伪代码

#include <vector>
using namespace std;
struct  Node
{
    int x;  //该节点在nodeMap中的坐标
    int y;

    int px;
    int py;

    int g;  //从起点到该点的步数
    int h;  //从该点带终点的估算距离
    int f;  //g+h
};

class Axing
{
public:
    Axing();//用来初始化矩阵，障碍等。
    ~Axing();
private:
    vector<vector<int>> nodeMap;        //可以移动到的点为1，障碍点为0也就是不能移动上去的。
    int countH(int curx,int cury,int endx,int endy);    //该算法可能是直接勾股定理，或者是曼哈顿算法等
    Node getMinFNode(vector<Node> &);    //这个函数是从接壤容器中取出F最小的点。返回坐标
    void addNode(vector<Node> &);       //将Node添加到容器中
    //获取一个节点可以移动到的节点，并调用handleNode()处理
    void getCanMoveNode(vector<Node> &canMove,vector<vector<bool>> &memo,Node &cur);
    //该函数处理一个节点，计算该节点的接壤节点存入canMove。
    void handleNode(vector<Node> &canMove,int x,int y,Node &cur);  
    
    //为了少穿点参数。就加了两个变量
    //不知道编程中能不能这样做。
    int endx;
    int endy;
public:
    vector<vector<int>> findPath(vector<Node> &canMove,vector<vector<bool>> &memo,int startX,int startY,int endX,int endY);
};

void Axing::getCanMoveNode(vector<Node> &canMove,vector<vector<bool>> &memo,Node &cur,Node &end)
{
    //从二叉堆canMove中取
}
void Axing::addNode(vector<Node> &canMove)
{
    //canMove以二叉堆的方式存放，.f值为key
}



void Axing::handleNode(vector<Node> &canMove,int x,int y,Node &cur)
{
    int pg=cur.g+1;
    int h=countH(x,y,_endx,_endy);
    int f=h+pg;
    Node node(x,y,px,py,h,f);
    canMove.push(std::move(node));
}


vector<vector<int>> Axing::findPath(int startX,int startY,int endX,int endY)
{
    vector<Node> canMove;           //该容器存放接壤的点，表示可移动上去
    vector<Node> hasPass;           //存放已经走过的Node，以便重建路径
    vector<vector<bool>> memo;      //该容器表示某个点是否已经走过了。

    Node startNode(startX,startY,startX,startY,0,0,0);
    
    addNode(canMove,std::move(startNode));
    while(! canMove.empty())
    {
        Node curNode = getMinFNode(canMove);
        
        int x=cur.x;
        int y=cur.y;
        //依次处理四个节点
        if(memo[x-1][y] == false )
        {

            handleNode(canMove,x-1,y,cur);
            memo[x-1][y] =true;
            if(x-1 == endX && y == endY)
            {
                break;
            }
        }
        if(memo[x+1][y] == false)
        {
            handleNode(canMove,x+1,y,cur);
            memo[x+1][y] =true;
            if(x+1 == endX && y == endY)
            {
                break;
            }
        }
        if(memo[x][y-1] == false)
        {
            handleNode(canMove,x,y-1,cur);
            memo[x][y-1] =true;
            if(x == endX && y-1 == endY)
            {
                break;
            }
        }
        if(memo[x][y+1] == false)
        {
            memo[x][y+1] =true;
            handleNode(canMove,x,y+1,cur);
            if(x == endX && y+1 == endY)
            {
                break;
            }
        }

        hasPass.push_back(std::move(curNode));
    }
    //下面就从从最后一个节点,到开始节点重建该路径
    
}