/*------------------------------------------------------------------*
 * Cycle Detection
 *-----------------------------------------------------------------*/

#include "bc_000_ListNode.h"

#include <iostream>
#include <vector>
#include <unordered_set>

int
cycleLength(std::shared_ptr<ListNode<int>> node) {
    int length = 0;
    auto head = node;
    do {
        node = node->next;
        length++;
        } while(node !=head && (node  != nullptr));

    return length;
}


void
advanceNode(std::shared_ptr<ListNode<int>> & node, int k) {
    while(k) {
        node = node->next;
        k--;
    }
}
    
std::shared_ptr<ListNode<int>> 
HasCycle(const std::shared_ptr<ListNode<int>>& head) {
    auto slow = head;
    auto fast = head;
    
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        
        if(slow == fast) {
            int length = cycleLength(slow);
            slow = head;
            advanceNode(slow, length);

            fast = head;

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
