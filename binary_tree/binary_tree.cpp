#include <cstdlib>
#include <iostream>
#include "binary_tree.h"

#define NULL_INTEGER 666666 

BiNode* createABinaryTree()
{
    int x;
    std::cout << "please input an integer(999999 is null)" << std::endl;
    std::cin >> x;
    if(x != NULL_INTEGER)
    {
        BiNode *node = new BiNode;
	if(node != NULL)
	{
	    node->x = x;
	    node->rChild = NULL;
	    node->lChild = NULL;
	}
	else
	{
	    std::cout << "new failed, no enough memory" << std::endl;
	    return NULL;
	}

        node->lChild = createABinaryTree();
        node->rChild = createABinaryTree();
        
        return node;	
     } 
     else
     {
        std::cout << "NUL node!" << std::endl;
	return NULL;
     }
}

void printBiTreePreOrder(BiNode *root)
{
    if(root == NULL)
    {
        return;
    }

    std::cout << root->x;
    if(root->lChild != NULL)
    {
        printBiTreePreOrder(root->lChild);
    }
    if(root->rChild != NULL)
    {
        printBiTreePreOrder(root->rChild);
    }
}
