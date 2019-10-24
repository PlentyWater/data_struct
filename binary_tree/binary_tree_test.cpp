#include <cstdio>
#include "binary_tree.h"

int main()
{
    const char *file = "trees/tree1.txt";
    BiNode *root = createBinaryTreebyLayerOrderfromFile(file);
    printf("layer order:\n");
    printBiTreeByLayerOrder(root);
    printf("Pre order:\n");
    visitBiTreebyPreOrderunRecur(root);
    printf("In  order:\n");
    visitBiTreebyInOrderunRecur(root);
    printf("Pos order:\n");
    visitBiTreebyPosOrderunRecur(root);
    printf("layer order:\n");
    printBiTreeByLayerOrder(root);
}
