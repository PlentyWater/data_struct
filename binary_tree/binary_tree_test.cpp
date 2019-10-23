#include <cstdio>
#include "binary_tree.h"

int main()
{
    BiNode *root = createBinaryTreebyLayerOrder();
    printf("layer order:\n");
    printBiTreeByLayerOrder(root);
    printf("Pre order:\n");
    visitBiTreebyPreOrderunRecur(root);
    printf("In  order:\n");
    visitBiTreebyInOrderunRecur(root);
}
