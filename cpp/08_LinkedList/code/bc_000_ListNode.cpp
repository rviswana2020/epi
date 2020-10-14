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
appendNode(std::shared_ptr<ListNode<int>> &head, int val) {

    if(head == nullptr) {
        head = std::make_shared<ListNode<int>>(val);
        return;
    }

    auto tmpNode = head;

    while(tmpNode && tmpNode->next) {
        tmpNode = tmpNode->next;
    }
    tmpNode->next = std::make_shared<ListNode<int>>(val);
}

//--------------------------------------------------------------------

void
createList(std::shared_ptr<ListNode<int>> &head, std::vector<int> vecList) {
    for(auto val : vecList) {
        appendNode(head, val);
    }
}

//--------------------------------------------------------------------

void
printList(std::shared_ptr<ListNode<int>> head) {
    while(head) {
        std::cout << head->data  << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

//--------------------------------------------------------------------

size_t 
listLength(std::shared_ptr<ListNode<int>> head) {
    size_t length = 0;
    
    while(head) {
        head = head->next;
        length++;
    }
    return length;
}

//--------------------------------------------------------------------
