#include <iostream>
#include <vector>
#include <cassert>

#include "bc_000_ListNode.h"

void
testCreateList() {
    std::vector<int> vecList{1, 2, 3, 4, 5};
    std::shared_ptr<ListNode<int>> listA;
    createList(listA, vecList);
    printList(listA);
}

void
testSearchNode() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 9};
    std::shared_ptr<ListNode<int>> head;
    createList(head, vecList);
    printList(head);

    auto searchPtr = searchList(head, 9);
    assert(searchPtr->data == 9);

    searchPtr = searchList(head, 7);
    assert(searchPtr == nullptr);
}

void
testInsertAndDelete() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 9};
    std::shared_ptr<ListNode<int>> head;
    createList(head, vecList);
    printList(head);

    auto searchPtr = searchList(head, 5);
    insertAfter(searchPtr, std::make_shared<ListNode<int>>(6));
    printList(head);

    searchPtr = searchList(head, 6);
    deleteAfter(searchPtr);
    printList(head);
}

int main() {
    testCreateList();
    testSearchNode();
    testInsertAndDelete();
}
