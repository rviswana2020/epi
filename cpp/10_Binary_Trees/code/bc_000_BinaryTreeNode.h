/*------------------------------------------------------
 * Binary Tree Node Type and apis declaration
 *----------------------------------------------------*/

#ifndef BINARY_TREE_NODE_H
#define BINARY_TREE_NODE_H

#include <memory>
#include <vector>

template <typename T>
struct BinaryTreeNode {
    T data;
    std::unique_ptr<BinaryTreeNode<T>> left, right;
};

void
createBinaryTree(std::unique_ptr<BinaryTreeNode<int>> & root, std::vector<int> &list);

void
printTree(std::unique_ptr<BinaryTreeNode<int>> &root);

#endif    //BINARY_TREE_NODE_H
