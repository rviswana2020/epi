/*----------------------------------------------------------------
 * Tests Doubly Linked List operations
 *--------------------------------------------------------------*/

#include <cassert>

#include "bc_001_DListNode.h"

void
testCreate() {
    std::vector<int> vecList {1, 2, 3, 4, 5};
    std::shared_ptr<DListNode> head;
    createList(head, vecList);
    printList(head);

    auto tailNode = getTailNode(head);
    reversePrintList(tailNode);
}

void
testSearch() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 9};
    std::shared_ptr<DListNode> head;
    createList(head, vecList);

    auto searchPtr = searchNode(head, 5);
    assert(searchPtr->data == 5);

    searchPtr = searchNode(head, 8);
    assert(searchPtr == nullptr);
}

void
testInsertAndDelete() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 9};
    std::shared_ptr<DListNode> head;
    createList(head, vecList);

    auto searchPtr = searchNode(head, 6);
    insertAfter(searchPtr, std::make_shared<DListNode>(7));
    printList(head);

    searchPtr = searchNode(head, 7);
    deleteAfter(searchPtr);
    printList(head);

    searchPtr = searchNode(head, 1);
    insertAfter(searchPtr, std::make_shared<DListNode>(0));
    printList(head);

    searchPtr = searchNode(head, 7);
    reversePrintList(searchPtr);
}


int
main() {
    testCreate();
    testSearch();
    testInsertAndDelete();

    return 0;
}
