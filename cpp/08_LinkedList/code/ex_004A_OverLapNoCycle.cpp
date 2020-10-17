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

    std::unordered_set<std::shared_ptr<ListNode<int>>> nodesInOneListSet;

    while(listA) {
        nodesInOneListSet.insert(listA);
        listA = listA->next;
    }

    while(listB) {
        if(nodesInOneListSet.find(listB) != nodesInOneListSet.end()) {
            return listB;
        }
        listB = listB->next;
    }

    return nullptr;
}

//--------------------------------------------------------------------
