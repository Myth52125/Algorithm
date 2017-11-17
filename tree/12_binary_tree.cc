#include <iostream>

struct Node
{
    Node *p;
    Node *l;
    Node *r;
    int key;
};

class Binary_tree
{
    public:
        
    private:
        Node* m_root;
    public:
        // 查找是具有一个给定的节点
        // 迭代实现
        Node* has_key_i(int key) const 
        {
            Node* cur = m_root;
            while(cur)
            {
                if(cur->key == key)
                {
                    return cur;
                }else if(cur->key>key){
                    cur=cur->l;
                }else if(cur->key<key){
                    cur=cur->r;
                }
            }
            return nullptr;
        }
        // 递归实现
        Node* has_key_r(int key)
        {
            return aux_has_key_r(root,key);
        }
    private:
    // 查找是具有一个给定的节点,迭代实现的辅助函数
    Node* aux_has_key_r(Node* cur,int key) const 
    {
        if(cur==nullptr || cur->key == key)
        {
            return cur;
        }else if(cur->key > key)
        {
            return aux_has_key_r(cur->l,key);
        }else if(cur->key <key)
        {
            return aux_has_key_r(cur->r,key);
        }
    }
}