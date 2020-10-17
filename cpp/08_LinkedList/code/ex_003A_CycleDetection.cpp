/*------------------------------------------------------------------*
 * Cycle Detection
 *-----------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <iostream>
#include <vector>
#include <unordered_set>

std::shared_ptr<ListNode<int>>
HasCycle(const std::shared_ptr<ListNode<int>> &head) {
    int cnt = 0;
    auto outerPtr = head;
    std::shared_ptr<ListNode<int>> cycleStart = nullptr;

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
