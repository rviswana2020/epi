/*--------------------------------------------------------------------
 * Doubly Linked List Definition and basic operations
 *------------------------------------------------------------------*/
#include <iostream>

#include "bc_001_DListNode.h"

void
appendNode(std::shared_ptr<DListNode> &head, int value) {
    std::shared_ptr<DListNode> newNode = std::make_shared<DListNode>(value);

    if(!head) {
        head = newNode;
        return;
    }

    auto tail = head;
    while(tail->next) {
        tail = tail->next;
    }
    tail->next = newNode;
    newNode->prev = tail;
}

//--------------------------------------------------------------------

void
printList(std::shared_ptr<DListNode> head) {
    while(head) {
        std::cout << head->data << " ";
        head = head->next;
    }

    std::cout << std::endl;
}

//--------------------------------------------------------------------

void
reversePrintList(std::shared_ptr<DListNode> tail) {
    while(tail) {
        std::cout << tail->data << " ";
        tail = tail->prev;
    }

    std::cout << std::endl;
}

//--------------------------------------------------------------------

std::shared_ptr<DListNode>
searchNode(std::shared_ptr<DListNode> head, int searchValue) {
    while(head && head->data != searchValue)  {
        head = head ->next;
    }
    return head;
}

//--------------------------------------------------------------------

void
createList(std::shared_ptr<DListNode>& head, std::vector<int> &vecList) {
    
    for(auto entry: vecList) {
        appendNode(head, entry);
    }
}

//--------------------------------------------------------------------
