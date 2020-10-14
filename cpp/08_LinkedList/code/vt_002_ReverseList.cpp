/*-------------------------------------------------------------------*
 * Reverse a Linked List.
 * Write a function that reverses a singly linked List. The
 * function should use no more than constant storage beyond
 * that needed for the list itself.
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
reverseList(std::shared_ptr<ListNode<int>> head) {

    auto dummy = std::make_shared<ListNode<int>>(-1);
    dummy->next = head;

    auto curNode = dummy->next;

    while(curNode && curNode->next) {
        auto nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = dummy->next;
        dummy->next = nextNode;
    }

    return dummy->next;
}

//--------------------------------------------------------------------
