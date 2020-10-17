/*------------------------------------------------------------------*
 * Cycle Detection
 *-----------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <iostream>
#include <vector>
#include <unordered_set>

std::shared_ptr<ListNode<int>> 
HasCycle(const std::shared_ptr<ListNode<int>>& head) {
    auto slow = head;
    auto fast = head;

    while(fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;

        if(fast == slow) {
            slow = head;
            while(slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return nullptr;
}

//--------------------------------------------------------------------
