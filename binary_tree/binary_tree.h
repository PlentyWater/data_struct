#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct BiTreeNode
{
    BiTreeNode *lChild;
    BiTreeNode *rChild;
    int x;
}BiNode;

BiNode* createABinaryTreebyPosOrder();
BiNode* createBinaryTreebyLayerOrder();
void printBiTreePreOrder(BiNode* root);
void printBiTreeByLayerOrder(BiNode* root);

void visitBiTreeunRecur(BiNode* root);
















#endif//END BINARY_TREE_H
