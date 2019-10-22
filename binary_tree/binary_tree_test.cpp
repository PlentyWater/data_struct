#include <cstdio>
#include "binary_tree.h"

int main()
{
    BiNode *root = createBinaryTreebyLayerOrder();
    //printf("Pre order:");
    //visitBiTreebyPreOrderunRecur(root);
    printf("In  order:");
    visitBiTreebyInOrderunRecur(root);
}
