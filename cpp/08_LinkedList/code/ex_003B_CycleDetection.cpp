/*------------------------------------------------------------------*
 * Cycle Detection
 *-----------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <iostream>
#include <vector>
#include <unordered_set>

std::shared_ptr<ListNode<int>>
HasCycle(const std::shared_ptr<ListNode<int>> &head) {
	auto temp = head;
    if(!temp)
        return nullptr;

    std::shared_ptr<ListNode<int>> cycleStartPtr = nullptr;
    std::unordered_set<std::shared_ptr<ListNode<int>>> visited;

    auto dummy = head;
    while(temp) {
        visited.insert(temp);
        auto found = visited.find(temp->next);
        if(found != visited.end()) {
            cycleStartPtr = head->next;
            break;
        }

        temp = temp->next;
    }

    return cycleStartPtr;
}

//--------------------------------------------------------------------
