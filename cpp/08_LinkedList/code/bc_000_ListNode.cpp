/*-------------------------------------------------------------------*
 * Basic singly linked List operations
 *  --appending a node
 *  --searching a node
 *  --printing list nodes
 *  --creating list from a vector
 *  --deleting a node
 *------------------------------------------------------------------*/

#include <iostream>

#include "bc_000_ListNode.h"

void
appendNode(std::shared_ptr<ListNode> &head, int val) {

    if(head == nullptr) {
        head = std::make_shared<ListNode>(val);
        return;
    }

    auto tmpNode = head;

    while(tmpNode && tmpNode->next) {
        tmpNode = tmpNode->next;
    }
    tmpNode->next = std::make_shared<ListNode>(val);
}

//--------------------------------------------------------------------

void
createList(std::shared_ptr<ListNode> &head, std::vector<int> vecList) {
    for(auto val : vecList) {
        appendNode(head, val);
    }
}

//--------------------------------------------------------------------

void
printList(std::shared_ptr<ListNode> head) {
    while(head) {
        std::cout << head->data  << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

//--------------------------------------------------------------------
