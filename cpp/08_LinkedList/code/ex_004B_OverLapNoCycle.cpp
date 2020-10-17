/*-------------------------------------------------------------------*
 * Given two linked lists and no cycles exist in both linked lists
 * check whether one list is overlapping with the other.
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
OverlappingNoCycleLists(std::shared_ptr<ListNode<int>> listA,
                          std::shared_ptr<ListNode<int>> listB) {

    std::shared_ptr<ListNode<int>> overlappingNode = nullptr;
    bool overlappingNodeFound = false;
    while(listA && !overlappingNodeFound) {
        auto dummy = listB;
        while(dummy) {
            if(dummy == listA) {
                overlappingNode = listA;
                overlappingNodeFound = true;
                break;
            }
            dummy = dummy->next;
        }
        listA = listA->next;
    }

    return overlappingNode;
}

//--------------------------------------------------------------------
