/*-------------------------------------------------------------- *
 * Merge two sorted input lists.  The output list should contain
 * elements from both input lists in ascending order.
 *--------------------------------------------------------------*/

#include <iostream>
#include <algorithm>

#include "bc_000_ListNode.h"

void
append(std::shared_ptr<ListNode<int>> & head, std::shared_ptr <ListNode<int>> &secondList) {
    head->next = secondList;
    secondList = secondList->next;
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>>
mergeSortedList(std::shared_ptr<ListNode<int>> ListA, std::shared_ptr<ListNode<int>> ListB) {

    std::shared_ptr<ListNode<int>> mergeList = std::make_shared<ListNode<int>>(-1);
    auto tmpList = mergeList;

    while(ListA && ListB) {
       append(tmpList,
              ListA->data < ListB->data ? ListA : ListB);
       tmpList = tmpList->next;
    }

    tmpList->next = ListA ? ListA : ListB;

    return mergeList->next;
}

//--------------------------------------------------------------------

void
testMergedList(std::vector<int> & vecListA, std::vector<int> & vecListB) {
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Input List A: ";
    for_each(vecListA.begin(), vecListA.end(),
            [](auto a)-> void {std::cout << a << " ";});
    std::cout << std::endl;

    std::cout << "Input List B: ";
    for_each(vecListB.begin(), vecListB.end(),
            [](auto a)->void {std::cout << a << " ";});
    std::cout << std::endl;

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
