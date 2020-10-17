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
