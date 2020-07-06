/*--------------------------------------------------------------------
 * Cycle Detection
 *   - Write a program that takes the head of a singly linked list
 *     and returns null if there is no cycle and
 *     returns beginning of cycle if there is one.
 *
 *  This code works only when we initialize walker = runner = head
 *  and move the test(waler == runner) into while body.
 *-----------------------------------------------------------------*/

#include <iostream>

#include "bc_000_ListNode.h"

std::shared_ptr<ListNode>
detectCycle(std::shared_ptr<ListNode> head) {
    if(!head)
        return nullptr;

    auto walker = head;
    auto runner = head;

    while(runner && runner->next && runner->next->next) {
        runner = runner->next->next;
        walker = walker->next;
        if(runner == walker)
            break;
    }

    if(!runner)
        return nullptr;

    walker = head;
    while(walker != runner) {
        walker = walker->next;
        runner = runner->next;
    }

    return walker;
}

//--------------------------------------------------------------------

void
testDetectCycle(std::vector<int> & vecList) {
    std::shared_ptr<ListNode> head;
    createList(head, vecList);

    printList(head);
    auto searchPtr1 = searchList(head, 7);
    auto searchPtr2 = searchList(head, 10);

    searchPtr2->next = searchPtr1;

    auto loopStart = detectCycle(head);

    if(!loopStart) {
        std::cout << "No loop detected" << std::endl;
        return;
    }

    std::cout << " loop start: " << loopStart
              << " value: " << loopStart->data << std::endl;
}

//--------------------------------------------------------------------

int
main() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    testDetectCycle(vecList);

    return 0;
}

//--------------------------------------------------------------------
