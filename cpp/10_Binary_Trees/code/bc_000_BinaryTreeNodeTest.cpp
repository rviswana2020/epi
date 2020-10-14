#include "bc_000_BinaryTreeNode.h"
#include <iostream>

int main() {
    std::cout << "--------------------------------------" << std::endl;
    std::unique_ptr<BinaryTreeNode<int>> root = nullptr;
    std::vector<int> vecList {5, 3, 9, 2, 4, 6, 10};

    //root = createBinaryTree(vecList);
    createBinaryTree(root, vecList);
    printTree(root);

    return 0;
}
