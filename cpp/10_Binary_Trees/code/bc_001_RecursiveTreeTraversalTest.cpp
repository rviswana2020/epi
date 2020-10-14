#include "bc_000_BinaryTreeNode.h"
#include <iostream>

extern void InorderTraversal(std::unique_ptr<BinaryTreeNode<int>> & root);
extern void PreorderTraversal(std::unique_ptr<BinaryTreeNode<int>> & root);
extern void PostorderTraversal(std::unique_ptr<BinaryTreeNode<int>> & root);

int main() {
    std::cout << "--------------------------------------" << std::endl;
    std::unique_ptr<BinaryTreeNode<int>> root = nullptr;
    std::vector<int> vecList {5, 3, 9, 2, 4, 6, 10};

    //root = createBinaryTree(vecList);
    createBinaryTree(root, vecList);
    printTree(root);
    std::cout << "Inorder Traversal: " << std::endl;
    InorderTraversal(root);
    std::cout << "Preorder Traversal: " << std::endl;
    PreorderTraversal(root);
    std::cout << "Postorder Traversal: " << std::endl;
    PostorderTraversal(root);

    return 0;
}
