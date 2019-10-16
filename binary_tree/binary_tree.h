#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BiTreeNode
{
    BiTreeNode *lChild;
    BiTreeNode *rChild;
    int x;
}BiNode;

BiNode* createABinaryTree();
void printBiTreePreOrder(BiNode* root);

















#endif//END BINARY_TREE_H
