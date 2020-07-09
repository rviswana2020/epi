/*------------------------------------------------------
 * Basic Singly Linked List operations
 *----------------------------------------------------*/

#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <memory>
#include <cassert>
#include <vector>

/*---------
 *ListNode
 *-------*/

struct ListNode {
    int data;
    std::shared_ptr<ListNode> next;

    ListNode(int val) : data {val}, next{nullptr} {}
    ListNode() : data {0}, next{nullptr} {}
};

/*-----
 * api
 *---*/

void
appendNode(std::shared_ptr<ListNode> &head, int val);

void
createList(std::shared_ptr<ListNode> &head, std::vector<int> vecList);

void
printList(std::shared_ptr<ListNode> head);

inline void
insertAfter(std::shared_ptr<ListNode> curNode, std::shared_ptr<ListNode>newNode) {
    assert(curNode && newNode);
    newNode->next = curNode->next;
    curNode->next = newNode;
}

inline void
deleteAfter(std::shared_ptr<ListNode> node) {
    if(node && node->next) {
        node->next = node->next->next;
    }
}

inline std::shared_ptr<ListNode>
searchList(std::shared_ptr<ListNode> head, int searchValue) {
    while(head && head->data != searchValue) {
        head = head->next;
    }

    return head;
}

size_t
listLength(std::shared_ptr<ListNode> head);

#endif  //LIST_NODE_H
