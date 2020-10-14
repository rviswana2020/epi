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

template<typename T>
struct ListNode {
    T data;
    std::shared_ptr<ListNode<T>> next;

    ListNode(T val) : data {val}, next{nullptr} {}
    ListNode() : data {0}, next{nullptr} {}
};

/*-----
 * api
 *---*/

void
appendNode(std::shared_ptr<ListNode<int>> &head, int val);

void
createList(std::shared_ptr<ListNode<int>> &head, std::vector<int> vecList);

void
printList(std::shared_ptr<ListNode<int>> head);

inline void
insertAfter(std::shared_ptr<ListNode<int>> curNode, std::shared_ptr<ListNode<int>>newNode) {
    assert(curNode && newNode);
    newNode->next = curNode->next;
    curNode->next = newNode;
}

inline void
deleteAfter(std::shared_ptr<ListNode<int>> node) {
    if(node && node->next) {
        node->next = node->next->next;
    }
}

inline std::shared_ptr<ListNode<int>>
searchList(std::shared_ptr<ListNode<int>> head, int searchValue) {
    while(head && head->data != searchValue) {
        head = head->next;
    }

    return head;
}

size_t
listLength(std::shared_ptr<ListNode<int>> head);

#endif  //LIST_NODE_H
