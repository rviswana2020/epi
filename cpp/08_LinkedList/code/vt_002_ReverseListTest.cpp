/*-------------------------------------------------------------------*
 * Test for Reverse a Linked List.
 * Write a function that reverses a singly linked List. The
 * function should use no more than constant storage beyond
 * that needed for the list itself.
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

extern std::shared_ptr<ListNode<int>>
reverseList(std::shared_ptr<ListNode<int>> head);

void
testReverseList(std::vector<int> & vecList) {
    std::cout << "------------------------------------" << std::endl;
    std::cout << "Given List: ";
    printVector(vecList);

    std::shared_ptr<ListNode<int>> inList;
    createList(inList, vecList);

    auto reversed{reverseList(inList)};
    std::cout << "Reversed List: ";
    printList(reversed);
    std::cout << "------------------------------------" << std::endl;
}

//--------------------------------------------------------------------

int
main() {
    std::vector<int> vecList {1, 13, 4, 6, 8, 9, 12};
    testReverseList(vecList);

    std::vector<int> vecListA {};
    testReverseList(vecListA);

    std::vector<int> vecListB {1};
    testReverseList(vecListB);
    return 0;
}

//--------------------------------------------------------------------
