#ifndef DLISTNODE_H
#define DLISTNODE_H

/*--------------------------------------------------------------------
 * Doubly Linked List Definition and basic operations
 *------------------------------------------------------------------*/

#include <memory>
#include <vector>

struct DListNode {
    int data;
    std::shared_ptr<DListNode> prev;
    std::shared_ptr<DListNode> next;

    DListNode(int val) : data{val}, prev {nullptr}, next {nullptr} {}
};

/*--------------------------------------------------------------------
 * Apis
 *------------------------------------------------------------------*/

void
appendNode(std::shared_ptr<DListNode> &head, int value);

void
printList(std::shared_ptr<DListNode> head);

void
reversePrintList(std::shared_ptr<DListNode> tail);

std::shared_ptr<DListNode>
searchNode(std::shared_ptr<DListNode> head, int searchValue);

void
createList(std::shared_ptr<DListNode> &head, std::vector<int> &vecList);

/*--------------------------------------------------------------------
 * inlines
 *------------------------------------------------------------------*/

inline void
insertAfter(std::shared_ptr<DListNode> curNode,
            std::shared_ptr<DListNode> newNode) {

    newNode->next = curNode->next;
    if (curNode->next)
        curNode->next->prev = newNode;
    newNode->prev = curNode;
    curNode->next = newNode;
}


inline void
deleteAfter(std::shared_ptr<DListNode> curNode) {
    if(curNode->next != nullptr) {
        auto delNode = curNode->next;
        curNode->next = delNode->next;
        if(delNode->next)
            delNode->next->prev = curNode;
    }
}

inline std::shared_ptr<DListNode>
getTailNode(std::shared_ptr<DListNode> head) {
    while(head && head->next) {
        head = head->next;
    }

    return head;
}

#endif  //DLISTNODE_H
