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
overlappingWithNoCycles(std::shared_ptr<ListNode<int>> listA,
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

std::shared_ptr<ListNode<int>>
overlappingWithNoCycles_2(std::shared_ptr<ListNode<int>> listA,
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

static void
advanceList(std::shared_ptr<ListNode<int>> &head, size_t cnt) {
    while(head && cnt) {
        head = head->next;
        cnt--;
    }
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>>
overlappingWithNoCycles_3(std::shared_ptr<ListNode<int>> listA,
                          std::shared_ptr<ListNode<int>> listB ) {

    int lenA = listLength(listA);
    int lenB = listLength(listB);

    int advanceCnt = abs(lenA - lenB);
    advanceList( (lenA > lenB) ? listA : listB, advanceCnt);

    while(listA && listB && listA != listB) {
        listA = listA->next;
        listB = listB->next;
    }

    return listA;
}

//--------------------------------------------------------------------

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
    auto overlapNode = overlappingWithNoCycles(listA, listB);

    if(overlapNode == nullptr)
        std::cout << "lists not overlapping...." << std::endl;
    else
        std::cout << "lists overlap at: " << overlapNode->data << std::endl;

    std::cout << "------------------------------------" << std::endl;
    overlapNode = overlappingWithNoCycles_2(listA, listB);

    if(overlapNode == nullptr)
        std::cout << "lists not overlapping...." << std::endl;
    else
        std::cout << "lists overlap at: " << overlapNode->data << std::endl;

    std::cout << "------------------------------------" << std::endl;
    overlapNode = overlappingWithNoCycles_3(listA, listB);

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
