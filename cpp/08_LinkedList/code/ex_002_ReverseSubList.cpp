/*-------------------------------------------------------------------*
 * ex002_ReverseSubList.cpp
 * Reverse a sublist within a list
 *------------------------------------------------------------------*/
#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
reverseSubList(std::shared_ptr<ListNode<int>> head, int start_idx, int end_idx) {

    std::shared_ptr<ListNode<int>> dummy = std::make_shared<ListNode<int>>(-1);
    dummy->next = head;

    auto tail = dummy;
    int numReverse = end_idx - start_idx;

    while(start_idx > 1 && tail) {
        tail = tail->next;
        start_idx--;
    }

    auto curNode = tail->next;

    while(curNode && curNode->next && numReverse> 0) {
        auto nextNode = curNode->next;
        curNode->next = nextNode->next;
        nextNode->next = tail->next;
        tail->next = nextNode;
        numReverse--;
    }

    return dummy->next;
}

//--------------------------------------------------------------------

void
test(std::vector<int> &vecList, int start_idx, int end_idx) {
    std::shared_ptr<ListNode<int>> head;
    createList(head, vecList);
    std::cout << "Original List: ";
    printList(head);

    auto reversed = reverseSubList(head, start_idx, end_idx);
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
