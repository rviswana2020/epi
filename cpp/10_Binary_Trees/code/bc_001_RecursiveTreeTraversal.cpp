/*-------------------------------------------------------------------*
 * Tree Traversal
   ** Inorder Traversal     <---- Visit Left, Root, Right
   ** Preorder Traversal    <---- Visit Root, Left, Right
   ** Postorder Traversal   <---- Visit Left, Right, Root
 *------------------------------------------------------------------*/

#include "bc_000_BinaryTreeNode.h"

#include <iostream>

void
InorderTraversalHelper(std::unique_ptr<BinaryTreeNode<int>> & root) {
    if(root) {
        InorderTraversalHelper(root->left);
        std::cout << root->data << " ";
        InorderTraversalHelper(root->right);
    }
}

//--------------------------------------------------------------------

void
InorderTraversal(std::unique_ptr<BinaryTreeNode<int>> & root) {
    InorderTraversalHelper(root);
    std::cout << std::endl;
}

//--------------------------------------------------------------------

void
PreorderTraversalHelper(std::unique_ptr<BinaryTreeNode<int>> & root) {
    if(root) {
        std::cout << root->data << " ";
        PreorderTraversalHelper(root->left);
        PreorderTraversalHelper(root->right);
    }
}

//--------------------------------------------------------------------

void
PreorderTraversal(std::unique_ptr<BinaryTreeNode<int>> & root) {
    PreorderTraversalHelper(root);
    std::cout << std::endl;
}

//--------------------------------------------------------------------

void
PostorderTraversalHelper(std::unique_ptr<BinaryTreeNode<int>> & root) {
    if(root) {
        PostorderTraversalHelper(root->left);
        PostorderTraversalHelper(root->right);
        std::cout << root->data << " ";
    }
}

//--------------------------------------------------------------------

void
PostorderTraversal(std::unique_ptr<BinaryTreeNode<int>> & root) {
    PostorderTraversalHelper(root);
    std::cout << std::endl;
}

//--------------------------------------------------------------------
