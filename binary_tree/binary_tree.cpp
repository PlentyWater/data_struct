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
    BiNode *node = NULL;
    int x = 0;
    printf("input integers(-666 is nil, -333 is end):");
    std::cin >> x;
    while(x != -333) {
        if(x != -666) {
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
        std::cin >> x;
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

    printf("root->lchild:%p, root->rchild:%p\n", root->lChild, root->rChild);
    return root;
}

BiNode* createBinaryTreebyLayerOrderfromFile(const char *file)
{
    if(file == NULL)
        return NULL;
    FILE *pf = fopen(file, "rb");
    if(pf == NULL) {
        printf("open file failed\n");
        return NULL;
    }

    std::vector<BiNode*> treeVec;
    char treeBuf[1000] = {0};
    char tmpBuf[20] = {0};
    int i = 0,k = 0;
    fread(treeBuf, 1, 1000, pf);
    fclose(pf);
    while(i < 1000){
        while((tmpBuf[k] = treeBuf[i]) != ' ' && tmpBuf[k] != '\n'){
            i++;
            k++;
        }
        tmpBuf[++k] = '\0';
        printf("%s ", tmpBuf);
        if(tmpBuf[0] <= '9' && tmpBuf[0] >= '0'){
            int x = atoi(tmpBuf);
            BiNode *node = new BiNode();
            node->x = x;
            treeVec.push_back(node);
        } else if(tmpBuf[0] == 'e'){
            break;
        } else {
            BiNode *node = NULL;
            treeVec.push_back(node);
        }
        i++;
        k = 0;
    }

    printf("\n");
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
    bool mHanded;
    bool visited;
    VNode():lHanded(false), rHanded(false),visited(false){}
    VNode(BiNode *nod):lHanded(false), rHanded(false),visited(false),mHanded(false),node(nod){}
};
//visit biniary tree unrecursively
void visitBiTreebyPreOrderunRecur(BiNode* root)
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
            delete vNode;
            vec.pop();
        }
    }
    printf("\n");
}

void visitBiTreebyPosOrderunRecur(BiNode* root)
{
    if(root == NULL)
        return;
    std::stack<VNode> vec;
    VNode vNode(root);
    vec.push(vNode);
    while(!vec.empty()) {
        VNode &tmpVNode = vec.top();
        if(!tmpVNode.lHanded) {
            tmpVNode.lHanded = true;
            if(tmpVNode.node->lChild != NULL) {
                VNode tmp(tmpVNode.node->lChild);
                vec.push(tmp);
            }
        } else if(!tmpVNode.rHanded) {
            tmpVNode.rHanded = true;
            if(tmpVNode.node->rChild != NULL) {
                VNode tmp(tmpVNode.node->rChild);
                vec.push(tmp);
            }
        } else {
            printf("%d  ", tmpVNode.node->x);
            vec.pop();
        }
    }
    printf("\n");
}

void visitBiTreebyInOrderunRecur(BiNode* root)
{
    if(root == NULL)
        return;
    std::stack<VNode> vec;
    VNode vNode(root);
    vec.push(vNode);
    while(!vec.empty()) {
        VNode &tmpVNode = vec.top();
        if(!tmpVNode.lHanded) {
            tmpVNode.lHanded = true;
            if(tmpVNode.node->lChild != NULL) {
                VNode tmp(tmpVNode.node->lChild);
                vec.push(tmp);
            }
        } else if(!tmpVNode.mHanded) {
            tmpVNode.mHanded = true;
            printf("%d  ", tmpVNode.node->x);
        } else if(!tmpVNode.rHanded) {
            tmpVNode.rHanded = true;
            if(tmpVNode.node->rChild != NULL) {
                VNode tmp(tmpVNode.node->rChild);
                vec.push(tmp);
            }
        } else {
            vec.pop();
        }
    }
    printf("\n");
}
