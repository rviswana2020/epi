/*-------------------------------------------------------------------*
 * vt_003_ReverseKSubList.cpp
 * Write a program which takes as input a singly linked List
 * and a non-negative integer k, and reverses the list k nodes
 * at a time.  If the number of nodes n in the list is
 * not multiple of k, leave the last n mod k nodes unchanged.
 * Do not change the data stored within  a node.
 *------------------------------------------------------------------*/

#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode<int>>
reverseKSubList(std::shared_ptr<ListNode<int>> head, int k) {

    std::shared_ptr<ListNode<int>> dummy = std::make_shared<ListNode<int>>(-1);
    dummy->next = head;

    auto tail = dummy;
    auto endptr = dummy;

    while(true) {
        int cnt = k;
        while(cnt > 0 && endptr) {
            endptr = endptr->next;
            cnt--;
        }

        if(cnt != 0)
            break;

        auto curNode = tail->next;
        endptr = endptr->next;

        while(curNode && (curNode->next != endptr)) {
            auto nextNode = curNode->next;
            curNode->next = nextNode->next;
            nextNode->next = tail->next;
            tail->next = nextNode;
        }

        tail = curNode;
        endptr = curNode;
        std::cout << "\tAt the end of each Iteration:  ";
        printList(dummy);
    }

    return dummy->next;
}

//--------------------------------------------------------------------

void
test_reverseKSubList(std::vector<int> & vecList, int k) {
    std::shared_ptr<ListNode<int>> head;

    createList(head, vecList);
    std::cout << "original List: " << "k=" << k << " is: ";
    printList(head);

    auto reversed = reverseKSubList(head, k);
    std::cout << "Final List: ";
    printList(reversed);
    std::cout << std::endl;
}

//--------------------------------------------------------------------

int
main() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    test_reverseKSubList(vecList, 3);
    test_reverseKSubList(vecList, 2);
    test_reverseKSubList(vecList, 7);

    return 0;
}


//--------------------------------------------------------------------
