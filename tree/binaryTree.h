#ifndef _MYTH52125_BINARYTREE_H_
#define _MYTH52125_BINARYTREE_H_

#include "Node.h"

namespace myth52125
{
namespace algorithm
{

class BinaryTree
{
public:
    BinaryTree();
    ~BinaryTree();
private:
    Node *_root;
public:
    void add(Node &node);
};


}
}



#endif