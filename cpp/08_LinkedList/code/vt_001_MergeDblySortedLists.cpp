/*-------------------------------------------------------------------
 * Merge two sorted Doubly Linked List
 *-----------------------------------------------------------------*/

#include <iostream>

#include "bc_001_DListNode.h"

void
appendDNodes(std::shared_ptr<DListNode> & merged,
             std::shared_ptr<DListNode> & newNode) {
        merged->next = newNode;
        newNode->prev = merged;

        newNode = newNode->next;
        merged = merged->next;
}

//--------------------------------------------------------------------

std::shared_ptr<DListNode>
mergeSortedList(std::shared_ptr<DListNode> ListA, std::shared_ptr<DListNode> ListB) {
    std::shared_ptr<DListNode> dummy = std::make_shared<DListNode>(-1);

    auto tail = dummy;

    while(ListA && ListB) {
        appendDNodes(tail,
                     ListA->data < ListB->data ? ListA:ListB);
    }

    tail->next = ListA ? ListA : ListB;

    if(ListA) {
        tail->next = ListA;
        ListA->prev = tail;
    }

    if(ListB) {
        tail->next = ListB;
        ListB->prev = tail;
    }

    auto returnNode = dummy->next;
    if(returnNode)
        returnNode->prev = nullptr;

    return returnNode;
}

//--------------------------------------------------------------------

void
testDblySortedMerge(std::vector<int> & vecListA, std::vector<int>& vecListB) {
    std::cout << "---------------------------------" << std::endl;
    std::shared_ptr<DListNode> ListA;
    std::shared_ptr<DListNode> ListB;


    createList(ListA, vecListA);
    createList(ListB, vecListB);


    std::cout << "first list: ";
    printList(ListA);

    std::cout << "second list: ";
    printList(ListB);

    auto merged = mergeSortedList(ListA, ListB);
    std::cout << "merged List: ";
    printList(merged);
}

//--------------------------------------------------------------------

int
 main() {
    std::vector<int> vecListA {1, 4, 56, 78, 98, 100};
    std::vector<int>vecListB {2, 34, 57, 99, 112};

    testDblySortedMerge(vecListA, vecListB);

    std::vector<int> emptyList {};

    testDblySortedMerge(emptyList, vecListB);
    testDblySortedMerge(vecListA, emptyList);
    testDblySortedMerge(emptyList, emptyList);

    return 0;
}

//--------------------------------------------------------------------
