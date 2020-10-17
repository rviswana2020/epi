/*-------------------------------------------------------------------*
 * ex002_ReverseSubList.cpp
 * Reverse a sublist within a list
 *------------------------------------------------------------------*/
#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
ReverseSublist(std::shared_ptr<ListNode<int>> L, int start, int finish) {
    if(start == finish)
        return L;

    auto dummyHead{ std::make_shared<ListNode<int>>(0, L)};
    auto sublistHead {dummyHead};

    int k = 1;
    while(k < start) {
        sublistHead = sublistHead->next;
        k++;
    }

    auto curNode = sublistHead->next;
    while((start != finish) && curNode && curNode->next) {
        auto nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = sublistHead->next;
        sublistHead->next = nextNode;
        start++;
    }

    return dummyHead->next;
}

//--------------------------------------------------------------------
