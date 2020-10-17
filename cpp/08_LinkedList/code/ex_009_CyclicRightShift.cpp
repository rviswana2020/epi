#include <iostream>
#include <vector>

#include "bc_000_ListNode.h"
//--------------------------------------------------------------------

std::shared_ptr<ListNode<int>> 
CyclicallyRightShiftListstd::(shared_ptr<ListNode<int>> L, int k) {
    if(L == nullptr)
        return L;

    int cnt = 1;
    auto tail = L;
    while(tail->next) {
        tail = tail->next;
        cnt++;
    }

    k = k % cnt;
    auto steps_to_new_head = cnt - k;

    if(k == 0)
        return L;

    tail->next = L;
    auto newTail = tail;
    while(steps_to_new_head) {
        newTail = newTail->next;
        steps_to_new_head--;
    }

    auto newHead = newTail->next;
    newTail->next = nullptr;

    return newHead;
}
