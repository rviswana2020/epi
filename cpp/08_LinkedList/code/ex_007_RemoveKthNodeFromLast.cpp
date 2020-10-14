/*-------------------------------------------------------------------*
 * Remove Kth node from end of the list
 *------------------------------------------------------------------*/

#include <iostream>
#include <cassert>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
deleteKthElementFromTail(std::shared_ptr<ListNode<int>> list, int pos) {
    assert(pos >= 1);

    std::shared_ptr<ListNode<int>> dummy = std::make_shared<ListNode<int>>();
    dummy->next = list;
    auto delNode = dummy;
    auto fwdPtr = dummy;

    while(pos > 0) {
        fwdPtr = fwdPtr->next;
        pos--;
    }

    while(fwdPtr->next != nullptr) {
        fwdPtr = fwdPtr->next;
        delNode = delNode->next;
    }

    if(delNode->next != nullptr)
        delNode->next = delNode->next->next;
    else
        delNode->next = nullptr;

    return dummy->next;
}

//--------------------------------------------------------------------

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
