/*-------------------------------------------------------------------*
 * ex002_ReverseSubListTest.cpp
 * Test for Reverse a sublist within a list
 *------------------------------------------------------------------*/
#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

extern std::shared_ptr<ListNode<int>>
ReverseSublist(std::shared_ptr<ListNode<int>> head, int start_idx, int end_idx);

void
test(std::vector<int> &vecList, int start_idx, int end_idx) {
    std::shared_ptr<ListNode<int>> head;
    createList(head, vecList);
    std::cout << "Original List: ";
    printList(head);

    auto reversed = ReverseSublist(head, start_idx, end_idx);
    std::cout << "Reversed sublist from "
              << start_idx << " to " << end_idx << ": ";
    printList(reversed);
}

//--------------------------------------------------------------------

int
main() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6 };
    test(vecList, 2, 4);
    test(vecList, 1, 5);

    return 0;
}

//--------------------------------------------------------------------
