#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <stack>
#include "binary_tree.h"

#define NULL_INTEGER 666666

//create a binary tree by pos order
BiNode* createABinaryTreebyPosOrder()
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
        node->lChild = createABinaryTreebyPosOrder();
        std::cout << "input right child" << std::endl;
        node->rChild = createABinaryTreebyPosOrder();

        return node;
     }
     else
     {
        std::cout << "NULL node!" << std::endl;
	    return NULL;
     }
}

BiNode* createBinaryTreebyLayerOrder()
{
    std::vector<BiNode*> treeVec;

    while(true) {
        int x = 0;
        char end = 0;
        BiNode *node = NULL;
        std::cout << "do all tree node are input(y/n):";
        std::cin >> end;
        if(end == 'y')
            break;

        std::cout << "please input an integer:";
        std::cin >> x;
        if(x != -666666) {
            node = new BiNode();
            if(node != NULL) {
                node->x = x;
                treeVec.push_back(node);
            } else {
                break;
            }
        } else {
            node = NULL;
            treeVec.push_back(node);
        }
    }

    BiNode *root = NULL;
    if(treeVec.size() > 0) {
        root = treeVec[0];
        BiNode *fatherNode = NULL;
        BiNode *childNode = NULL;
        int c = 1;
        for(int i = 0; i < treeVec.size(); i++) {
            fatherNode = treeVec[i];
            if(fatherNode != NULL) {
                fatherNode->lChild = treeVec[c++];
                fatherNode->rChild = treeVec[c++];
            }
        }
    }

    return root;
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
        _printBiTreePreOrder(root->lChild);
    }
    if(root->rChild != NULL)
    {
        _printBiTreePreOrder(root->rChild);
    }
}

void printBiTreePreOrder(BiNode *root)
{
    _printBiTreePreOrder(root);
    printf("\n");
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
    std::cout << "level " << level << ": ";
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
    printf("\n");
}
struct VNode {
    BiNode *node;
    bool lHanded;
    bool rHanded;
    bool visited;
    VNode():lHanded(false), rHanded(false),visited(false){}
};
//visit biniary tree unrecursively
void visitBiTreeunRecur(BiNode* root)
{
    if(root == NULL)
        return;

    std::stack<VNode*> vec;
    VNode* vNode = new VNode();
    vNode->node = root;
    vec.push(vNode);
    while(!vec.empty()) {
        vNode = vec.top();
        if(!vNode->visited) {
            printf("%d  ", vNode->node->x);
            vNode->visited = true;
        }
        if(!vNode->lHanded) {
            if(vNode->node->lChild != NULL) {
                VNode* vLNode = new VNode();
                vLNode->node = vNode->node->lChild;
                vec.push(vLNode);
            }
            vNode->lHanded = true;
        } else if(!vNode->rHanded) {
            if(vNode->node->rChild != NULL) {
                VNode* vRNode = new VNode();
                vRNode->node = vNode->node->rChild;
                vec.push(vRNode);
            }
            vNode->rHanded = true;
        } else {
            delete vNode->node;
            vec.pop();
        }
    }
    printf("\n");
}

