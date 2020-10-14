/*-------------------------------------------------------------------*
 * ex002_ReverseSubList.cpp
 * Reverse a sublist within a list
 *------------------------------------------------------------------*/
#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
reverseSubList(std::shared_ptr<ListNode<int>> head, int start_idx, int end_idx) {

    std::shared_ptr<ListNode<int>> dummy = std::make_shared<ListNode<int>>(-1);
    dummy->next = head;

    auto tail = dummy;
    int numReverse = end_idx - start_idx;

    while(start_idx > 1 && tail) {
        tail = tail->next;
        start_idx--;
    }

    auto curNode = tail->next;

    while(curNode && curNode->next && numReverse> 0) {
        auto nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = tail->next;
        tail->next = nextNode;
        numReverse--;
    }

    return dummy->next;
}

//--------------------------------------------------------------------
