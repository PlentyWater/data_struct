#include <cstdlib>
#include <iostream>
#include <queue>
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
        std::cout << "inpute left child" << std::endl;
        node->lChild = createABinaryTree();
        std::cout << "input right child" << std::endl;
        node->rChild = createABinaryTree();
        
        return node;	
     } 
     else
     {
        std::cout << "NULL node!" << std::endl;
	return NULL;
     }
}

void _printBiTreePreOrder(BiNode *root)
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

void printBiTreePreOrder(BiNode *root)
{
    _printBiTreePreOrder(root);
    std::cout << std::endl;
}

void printBiTreeByLayerOrder(BiNode *root)
{
      if(root == NULL)
      {
          std::cout << "parameter error, root is NULL" << std::endl;
          return;
      }
    std::queue<BiNode*> treeQueue;
    treeQueue.push(root);
    BiNode *last = root;
    BiNode *nLast = NULL;
    BiNode *cur = NULL;
    int level = 1;
    std::cout << "level " << level << ":";
    while(!treeQueue.empty())
    {
        cur = treeQueue.front();
        if(cur != NULL)
        {
            if(cur->lChild != NULL)
            {
                treeQueue.push(cur->lChild);
                nLast = cur->lChild;
            }
            if(cur->rChild != NULL)
            {
                treeQueue.push(cur->rChild);
                nLast = cur->rChild;
            }
	}
        else
	{
            std::cout << std::endl;
            std::cout << "some error, meet NULL pointer" << std::endl;
            return;
	}
        treeQueue.pop();
        std::cout << cur->x << " ";
	if(cur == last && !treeQueue.empty())
        {
            level++;
            std::cout << std::endl << "level " << level << ": ";
            last = nLast;
	}
    }
}

