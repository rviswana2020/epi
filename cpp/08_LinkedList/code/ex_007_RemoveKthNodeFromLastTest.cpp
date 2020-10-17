/*-------------------------------------------------------------------*
 * Remove Kth node from end of the list
 *------------------------------------------------------------------*/

#include <iostream>
#include <cassert>

#include "bc_000_ListNode.h"

extern std::shared_ptr<ListNode<int>>
deleteKthElementFromTail(std::shared_ptr<ListNode<int>> list, int pos);

void
testDeleteKthElementFromTail(std::vector<int> &vecList, int pos) {
    std::shared_ptr<ListNode<int>> head;
    createList(head, vecList);
    std::cout << "Original List:  ";
    printList(head);

    auto newHead = deleteKthElementFromTail(head, pos);

    std::cout << "After deleting " << pos << " element from tail: ";
    printList(newHead);
}

//--------------------------------------------------------------------

int main() {
    int pos = 1;
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 7, 8 };
    testDeleteKthElementFromTail(vecList, pos);

    pos = 7;
    testDeleteKthElementFromTail(vecList, pos);

    pos = 8;
    testDeleteKthElementFromTail(vecList, pos);

    return 0;
}

//--------------------------------------------------------------------
