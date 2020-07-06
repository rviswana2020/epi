/*------------------------------------------------------------------*
 * Cycle Detection
 *-----------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <iostream>
#include <vector>
#include <unordered_set>

std::shared_ptr<ListNode>
cycleDetection(std::shared_ptr<ListNode> head) {
    int cnt = 0;
    auto outerPtr = head;
    std::shared_ptr<ListNode> cycleStart = nullptr;

    bool cycleDetected = false;
    while(outerPtr && !cycleDetected) {
        cnt++;
        int innerCnt = 0;
        auto innerPtr = head;
        while(innerCnt < cnt - 1) {
            if(innerPtr == outerPtr) {
                cycleDetected = true;
                cycleStart = innerPtr;
                break;
            }
            innerCnt++;
            innerPtr = innerPtr->next;
        }
        outerPtr = outerPtr->next;
    }

    return cycleStart;
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode>
cycleDetection2(std::shared_ptr<ListNode> head) {

    if(!head)
        return nullptr;

    std::shared_ptr<ListNode> cycleStartPtr = nullptr;
    std::unordered_set<std::shared_ptr<ListNode>> visited;

    auto dummy = head;
    while(head) {
        visited.insert(head);
        auto found = visited.find(head->next);
        if(found != visited.end()) {
            cycleStartPtr = head->next;
            break;
        }

        head = head->next;
    }

    return cycleStartPtr;
}

//--------------------------------------------------------------------

std::shared_ptr<ListNode>
cycleDetection3(std::shared_ptr<ListNode> head) {
    if(!head)
        return nullptr;

    auto runner = head;
    auto walker = head;
    bool hasCycle = false;

    while(runner && runner ->next && runner->next->next) {
        runner = runner->next->next;
        walker = walker->next;

        if(runner == walker) {
            hasCycle = true;
            break;
        }
    }

    if(!hasCycle)
        return nullptr;

    size_t cycleLength = 0;
    do {
        walker = walker->next;
        cycleLength++;
    } while(walker != runner);

    walker = head;
    while(cycleLength) {
        walker = walker->next;
        cycleLength--;
    }

    runner = head;

    while(runner != walker) {
        walker = walker->next;
        runner = runner->next;
    }

    return walker;
}

//--------------------------------------------------------------------

void
testCycleDetection(std::vector<int> & vecList, bool createLoop) {
    std::shared_ptr<ListNode> head;
    createList(head, vecList);

    if(createLoop) {
        auto searchPtr1 = searchList(head, 10);
        auto searchPtr2 = searchList(head, 1);

        searchPtr1->next = searchPtr2;
    }

    std::cout << "------------------------------------" << std::endl;
    auto loopStartPtr = cycleDetection(head);

    if(!loopStartPtr)
        std::cout << "No cycles detected" << std::endl;
    else
        std::cout << "Cycle detected and start at: "
                  << loopStartPtr->data << std::endl;

    std::cout << "------------------------------------" << std::endl;
    loopStartPtr = cycleDetection2(head);

    if(!loopStartPtr)
        std::cout << "No cycles detected" << std::endl;
    else
        std::cout << "Cycle detected and start at: "
                  << loopStartPtr->data << std::endl;

    std::cout << "------------------------------------" << std::endl;
    loopStartPtr = cycleDetection3(head);

    if(!loopStartPtr)
        std::cout << "No cycles detected" << std::endl;
    else
        std::cout << "Cycle detected and start at: "
                  << loopStartPtr->data << std::endl;

}

//--------------------------------------------------------------------

int
main() {
    std::vector<int> vecList {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    testCycleDetection( vecList, true);
    testCycleDetection( vecList, false);
    return 0;
}

//--------------------------------------------------------------------
