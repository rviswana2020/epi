/*-------------------------------------------------------------------*
 * Given two linked lists and no cycles exist in both linked lists
 * check whether one list is overlapping with the other.
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

#include "bc_000_ListNode.h"

extern 
std::shared_ptr<ListNode<int>>
     OverlappingNoCycleLists(std::shared_ptr<ListNode<int>> listA,
                             std::shared_ptr<ListNode<int>> listB);

void
testOverlapping(bool addOverlap) {
    std::vector<int> vecListA {1, 2, 3, 4, 5, 6 };
    std::vector<int> vecListB {2, 4, 8, 9, 10 };

    std::shared_ptr<ListNode<int>> listA;
    std::shared_ptr<ListNode<int>> listB;

    createList(listA, vecListA);
    createList(listB, vecListB);

    if(addOverlap) {
        auto searchLastNode = searchList(listA, 6);
        searchLastNode->next = searchList(listB, 8);
    }

    std::cout << "------------------------------------" << std::endl;
    auto overlapNode = OverlappingNoCycleLists(listA, listB);

    if(overlapNode == nullptr)
        std::cout << "lists not overlapping...." << std::endl;
    else
        std::cout << "lists overlap at: " << overlapNode->data << std::endl;
}

//--------------------------------------------------------------------

int
main() {
    testOverlapping(true);
    testOverlapping(false);

    return 0;
}

//--------------------------------------------------------------------
