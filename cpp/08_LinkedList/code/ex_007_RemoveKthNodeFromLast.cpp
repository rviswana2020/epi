/*-------------------------------------------------------------------*
 * Remove Kth node from end of the list
 *------------------------------------------------------------------*/

#include <iostream>
#include <cassert>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
deleteKthElementFromTail(std::shared_ptr<ListNode<int>> list, int pos) {
    assert(pos >= 1);

    std::shared_ptr<ListNode<int>> dummy = std::make_shared<ListNode<int>>();
    dummy->next = list;
    auto delNode = dummy;
    auto fwdPtr = dummy;

    while(pos > 0) {
        fwdPtr = fwdPtr->next;
        pos--;
    }

    while(fwdPtr->next != nullptr) {
        fwdPtr = fwdPtr->next;
        delNode = delNode->next;
    }

    if(delNode->next != nullptr)
        delNode->next = delNode->next->next;
    else
        delNode->next = nullptr;

    return dummy->next;
}

//--------------------------------------------------------------------
