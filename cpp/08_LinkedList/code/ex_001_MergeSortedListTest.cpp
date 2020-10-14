/*-------------------------------------------------------------- *
 * Test for Merge two sorted input lists.  The output list should
 * contain elements from both input lists in ascending order.
 *--------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <iostream>

extern std::shared_ptr<ListNode<int>>
mergeSortedList(std::shared_ptr<ListNode<int>> ListA, std::shared_ptr<ListNode<int>> ListB);

void
testMergedList(std::vector<int> & vecListA, std::vector<int> & vecListB) {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Input List A: ";
    printVector(vecListA);

    std::cout << "Input List B: ";
    printVector(vecListB);

    std::shared_ptr<ListNode<int>> ListA;
    std::shared_ptr<ListNode<int>> ListB;

    createList(ListA, vecListA);
    createList(ListB, vecListB);

    auto mergedList = mergeSortedList(ListA, ListB);

    std::cout << "merged List: ";
    printList(mergedList);
    std::cout << "--------------------------------" << std::endl;
}

//--------------------------------------------------------------------

int
main() {
    std::vector<int> vecListA {1, 20, 24, 45, 68};
    std::vector<int> vecListB { 3, 56, 87, 90 };
    testMergedList(vecListA, vecListB);

    std::vector<int> vecListA1;
    testMergedList(vecListA1, vecListB);
    testMergedList(vecListA, vecListA1);
    testMergedList(vecListA1, vecListA1);

    return 0;
}

//--------------------------------------------------------------------
