/*-------------------------------------------------------------------*
 * Basic Tree apis
   ** Creating a Binary Tree
   ** Printing a Binary Tree given the root node
 *-------------------------------------------------------------------*/

#include "bc_000_BinaryTreeNode.h"

#include <iostream>

static void
createBinaryTreeHelper(std::unique_ptr<BinaryTreeNode<int>> &root, int elem) {
    if(root == nullptr) {
        root = std::make_unique<BinaryTreeNode<int>>();
        root->data = elem;
    }
    else if(elem < root->data) {
        createBinaryTreeHelper(root->left, elem);
    }
    else {
        createBinaryTreeHelper(root->right, elem);
    }
}

//--------------------------------------------------------------------

void
createBinaryTree(std::unique_ptr<BinaryTreeNode<int>> & root,
                 std::vector<int> & list) {
    for(auto elem : list) {
        createBinaryTreeHelper(root, elem);
    }
}

//--------------------------------------------------------------------

static void
printTreeHelper(std::unique_ptr<BinaryTreeNode<int>> &root,
                std::string indent) {
    const std::string increment {"   "};
    if(root) {
        printTreeHelper(root->right, indent + increment);
        std::cout << indent << root->data << std::endl;
        printTreeHelper(root->left, indent + increment);
    }
}

//--------------------------------------------------------------------

void
printTree(std::unique_ptr<BinaryTreeNode<int>> &root) {
    printTreeHelper(root, "");
}

//--------------------------------------------------------------------
