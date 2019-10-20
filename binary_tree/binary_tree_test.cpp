#include "binary_tree.h"

int main()
{
    BiNode *root = createBinaryTreebyLayerOrder();
    printBiTreeByLayerOrder(root);
}
