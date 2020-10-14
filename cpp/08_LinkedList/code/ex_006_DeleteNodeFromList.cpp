/*-------------------------------------------------------------------*
 * Delete Node from Singly Linked List in one pass
 * Assume that the node to be deleted will not be the tail node.
 * You only be provided with the node to be deleted.
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

void
deleteNodeFromList(std::shared_ptr<ListNode<int>> delNode) {
        delNode->data = delNode->next->data;
        delNode->next = delNode->next->next;
}

//--------------------------------------------------------------------

void
testDeleteANode(std::vector<int> &vecList) {
    std::shared_ptr<ListNode<int>> head;
    createList(head, vecList);
    std::cout << "original list: ";
    printList(head);

    auto getNodeFromList = searchList(head, 5);
    assert(getNodeFromList != nullptr);

    deleteNodeFromList(getNodeFromList);

    std::cout << "list after deletion: ";
    printList(head);
}

//--------------------------------------------------------------------

int main() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 7, 9};

    testDeleteANode(vecList);
    return 0;
}

//--------------------------------------------------------------------
