/*-------------------------------------------------------------------*
 * Given two linked lists and no cycles exist in both linked lists
 * check whether one list is overlapping with the other.
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

#include "bc_000_ListNode.h"

//--------------------------------------------------------------------

int
listLengthA(std::shared_ptr<ListNode<int>> node) {
    int length = 0;
    while(node) {
        node = node->next;
        length++;
    }
    return length;
}

//--------------------------------------------------------------------

void
advanceNode(std::shared_ptr<ListNode<int>> &head, int k) {
    while(k) {
        head = head->next;
        k--;
    }
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>> 
OverlappingNoCycleLists(std::shared_ptr<ListNode<int>> l0, std::shared_ptr<ListNode<int>> l1) {
    auto node0_length = listLengthA(l0);
    auto node1_length = listLengthA(l1);

    auto diff = abs(node0_length - node1_length);
    advanceNode(node0_length > node1_length ? l0 : l1, diff);

    while(l0 != l1) {
        l0 = l0->next;
        l1 = l1->next;
    }
    
    return l0;
}

//--------------------------------------------------------------------
